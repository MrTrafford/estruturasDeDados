#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

void ajuda() {
	printf("       Ajuda de Comandos\n");
	printf("\"D\"i + [posição]: Descobre uma casa oculta.\n");
	printf("\"V\" + [Posição]: Sinaliza com uma bandeira vermelha.\n");
	printf("\"A\" + [Posição]: Sinaliza com uma bandeira amarela.\n");
	printf("\"I\": Consulta informações atuais sobre o jogo.\n");
	printf("\"H\": Abre o menu de ajuda e comandos.\n");
	printf("\n    Como Usar os comandos com posição\n");
	printf("Como mencionado, alguns comandos você tem que especificar a posição.\n");
	printf("Por exemplo. Para \"D\", que descobre uma casa, basta digitar \"0 0\" após a tecla de comando para descobrir a casa nessa posição.\n");
	system("pause");
}

void inform(int *i, int seed) {
	printf("       Informações Sobre O Jogo\n");
	printf("Semente: %d\n", seed);
	printf("Número de jogadas: %d\n", i[0]);
	printf("Minas restantes: %d\n", i[1]);
	printf("Bandeiras colocadas: %d\n", i[2]);
	printf("Quadrados desconhecidos: %d\n", i[3]);
	system("pause");
}

void limparmapa(char s, int tamanho, char matriz[tamanho][tamanho]) {
	for (int ln = 0; ln < tamanho; ln++) {
		for (int col = 0; col < tamanho; col++) {
			matriz[ln][col] = s;
		}
	}
}

int preenchimento(int tamanho, char matriz[tamanho][tamanho]) {
	int cont = 0, total = tamanho * tamanho;
	for (int pos = 0; pos < total; pos++) {
		int ln = pos / tamanho;
		int col = pos % tamanho;
		if (matriz[ln][col] == 'Z') {
			for (int ln2 = ln - 1, col2 = col - 1; ln2 <= ln + 1; col2++) {
				if (ln2 >= 0 && ln2 < tamanho && col2 >= 0 && col2 < tamanho) {
					if (matriz[ln2][col2] == '0') {
						matriz[ln2][col2] = 'Z';
						cont++;
					} else if (matriz[ln2][col2] >= '1' && matriz[ln2][col2] <= '8') {
						matriz[ln2][col2] = 'N';
						cont++;
					}
				}
				if (col2 == col + 1) {
					col2 = col - 2;
					ln2++;
				}
			}
		}
	}
	if (cont) {
	return preenchimento(tamanho, matriz);
	}
	return 0;
}

void gerar(int tamanho, char matriz[tamanho][tamanho], int minas) {
	limparmapa('0', tamanho, matriz);
	int ln, col, cont;
	for (cont = 0; cont != minas; ) {
		ln = rand() % tamanho;
		col = rand() % tamanho;
		if (matriz[ln][col] == '0') {
			matriz[ln][col] = '*';
			cont++;
		}
	}
	for (ln = 0; ln < tamanho; ln++) {
		for (col = 0; col < tamanho; col++) {
			cont = 0;
			if (matriz[ln][col] == '0') {
				for (int ln2 = ln - 1; ln2 <= ln + 1; ln2++) {
					for (int col2 = col - 1; col2 <= col + 1; col2++) {
						if (ln2 >= 0 && ln2 < tamanho && col2 >= 0 && col2 < tamanho && matriz[ln2][col2] == '*') {
							cont++;
						}
					}
				}
				matriz[ln][col] = '0' + cont;
			}
		}
	}
}

void exibir(int tamanho, char matriz1[tamanho][tamanho], char matriz2[tamanho][tamanho]) {
	for (int ln = 0; ln < tamanho; ln++) {
		for (int col = 0; col < tamanho; col++) {
			if (matriz2[ln][col] == 'Z' || matriz2[ln][col] == 'N' || matriz1[ln][col] == '!' || matriz1[ln][col] == '?') {
				printf("%c", matriz1[ln][col]);
			} else {
				printf("#");
			}
		}
		printf("\n");
	}
}

int pos_valida(int tamanho, int posln, int poscol) {
	if (posln >= 0 && posln < tamanho && poscol >= 0 && poscol < tamanho) {
		return 1;
	} else {
		return 0;
	}
}

int descobrir(int tamanho, char matriz[tamanho][tamanho], int posln, int poscol) {
	if (matriz[posln][poscol] == '0') {
		matriz[posln][poscol] = 'Z';
		preenchimento(tamanho, matriz);
	} else if (matriz[posln][poscol] == '*') {
		return 1;
	} else if (matriz[posln][poscol] == 'Z' || matriz[posln][poscol] == 'N') {
		printf("Essa casa já está descoberta, seu bobinho.\n");
	} else {
		matriz[posln][poscol] = 'N';
	}
	return 0;
}

char sinalizar_v(int tamanho, char matriz1[tamanho][tamanho], char matriz2[tamanho][tamanho], int posln, int poscol) {
	if (matriz2[posln][poscol] == 'Z' || matriz2[posln][poscol] == 'N') {
		printf("Por que raios você quer colocar uma bandeira numa casa já revelada?\n");
	} else {
		if (matriz1[posln][poscol] == '!') {
			return matriz2[posln][poscol];
		} else {
			return '!';
		}
	}
	return matriz1[posln][poscol];
}

char sinalizar_a(int tamanho, char matriz1[tamanho][tamanho], char matriz2[tamanho][tamanho], int posln, int poscol) {
	if (matriz2[posln][poscol] == 'Z' || matriz2[posln][poscol] == 'N') {
		printf("Por que raios você quer colocar uma bandeira numa casa já revelada?\n");
	} else {
		if (matriz1[posln][poscol] == '?') {
			return matriz2[posln][poscol];
		} else {
			return '?';
		}
	}
	return matriz1[posln][poscol];
}

void calcular_info(int *i, int minas, int tamanho, char matriz1[tamanho][tamanho], char matriz2[tamanho][tamanho]) {
	int cont_conecidos = 0;
	i[2] = 0;
	for (int ln = 0; ln < tamanho; ln++) {
		for (int col = 0; col < tamanho; col++) {
			if (matriz2[ln][col] == 'Z' || matriz2[ln][col] == 'N') {
				cont_conecidos++;
			}
			if (matriz1[ln][col] == '!') {
				i[2]++;
			}
		}
	}
	i[1] = minas - i[2];
	i[3] = tamanho * tamanho - cont_conecidos;
}

int vitoria(int *i, int minas) {
	if (i[1] == 0 && i[2] == i[3] && i[3] == minas) {
		return 1;
	}
	return 0;
}

void tela_vitoria(int tamanho, char matriz1[tamanho][tamanho], char matriz2[tamanho][tamanho]) {
	Beep(262, 300);
	Beep(330, 300);
	Beep(392, 300);
	Beep(524, 300);
	limparmapa('Z', tamanho, matriz2);
	Sleep(500);
	printf("Parabéns!\n");
	Sleep(500);
	printf("Você venceu!\n");
	Sleep(500);
	printf("Todas as minas foram encontradas corretamente e desativadas.\n\n");
	exibir(tamanho, matriz1, matriz2);
}

void tela_derrota(int tamanho, char matriz1[tamanho][tamanho], char matriz2[tamanho][tamanho]) {
	for (int ln = 0; ln < tamanho; ln++) {
		for (int col = 0; col < tamanho; col++) {
			if (matriz1[ln][col] == '!' || matriz1[ln][col] == '?') {
				matriz1[ln][col] = matriz2[ln][col];
			}
		}
	}
	limparmapa('Z', tamanho, matriz2);
	Beep(294, 1000);
	Beep(277, 1000);
	Beep(262, 2000);
	Sleep(500);
	printf("CABUM!!!!!!\n");
	Sleep(2000);
	printf("Você perdeu!\n");
	Sleep(500);
	printf("Você não foi cauteloso suficiente e sem querer explodiu uma mina.\n");
	exibir(tamanho, matriz1, matriz2);
}

int main() {
	setlocale(LC_ALL, ".UTF-8");
	char cmd = 0;
	printf("CAMPO MINADO!\n");
	printf("Com certeza você já ouviu falar em um jogo parecido coom esse ou similar. O clássico, e talvez infame para muitos, Campo Minado.\n");
	printf("Não?! Então senta que lá vem explicação.\n\n");
	printf("Basicamente existe um mapa, que é um campo desconhecido. Você deve selecionar os quadrados para revelá-los e assim conhecê-los.\n");
	printf("Mascuidado!\n");
	printf("Nesse campo, há diversas minas. Caso você tente descobrir uma casa que contenha alguma mina, ela explode e é fim de jogo!.\n");
	printf("\"Mas como vou saber onde tem mina?\"\n");
	printf("Não se preocupe, jovem gafanhoto. Em qualquer casa que não tenha mina, há um número de 0 a 8, que indicam quantas minas há em volta dela. Exemplo, se a casa mostrar o número 2, significa que há exatamente duas minas imediatamente em volta dela, que podem estar em cima, em baixo, à esquerda, à direita, no canto superior esquerdo, no canto superior direito, no canto inferior esquerdo, ou no canto inferior direito.\n");
	printf("Se você achar que alguma casa tem uma mina, você pode marcá-la com uma bandeira, representadas como: \"!\" (ponto de exclamação) para bandeira vermelha e \"?\" (ponto de interrogação) para bandeira amarela.\n");
	printf("Você ganha quando conseguir revelar todas as casas sem minas e marcar todas as casas com minas com bandeira vermelha. Sim, tem que ser a vermelha.\n");
	printf("Para descobrir uma casa, basta apertar \"D\" e digitar as coordenadas. Para colocar uma bandeira vermelha, aperte \"V\", e para colocar uma bandeira amarela, aperte \"A\". A qualquer momento durante a partida, você pode consultar informações sobre o jogo apertando \"I\", ou ajuda de comandos apertando \"H\".\n");
	printf("Pronto para o desafio?\n");
	printf("Aperte \"S\" para começar");
	do {
		cmd = getch();
		if (cmd != 'S' && cmd != 's') {
			printf("Erro! Comando não reconhecido.\n");
		}
	} while (cmd != 'S' && cmd != 's');
	system("cls");
	printf("Escolha o nível de dificuldade.\n");
	printf("1. Iniciante (7x7, 5 minas)\n");
	printf("2. Novato (9x9, 10 minas)\n");
	printf("3. Intermediário (16x16, 40 minas)\n");
	printf("4. Expert (22x22, 100 minas)\n");
	printf("5. Inferno (34x34, 250 minas)\n");
	do {
		cmd = getch();
		if (cmd < '1' || cmd > '5') {
			printf("Erro! Comando não reconhecido. Tente novamente.\n");
		}
	} while (!(cmd >= '1' && cmd <= '5'));
	int dif = cmd - '0';
	cmd = '\0';
	system("cls");
	printf("Deseja adicionar uma semente específica?\n");
	int seed;
	do {
		cmd = getch();
		if (cmd == 's' || cmd == 'S') {
			printf("Digite a semente.\n");
			scanf("%d", &seed);
		} else if (cmd == 'n' || cmd == 'N') {
			seed = time(NULL);
		} else {
			printf("Erro. Comando não reconhecido. Tente de novo!");
		}
	} while (cmd != 'S' && cmd != 's' && cmd != 'N' && cmd != 'n');
	srand(seed);
	int tamanho, minas;
	switch (dif) {
		case 1:
			tamanho = 7;
			minas = 5;
			break;
		case 2:
			tamanho = 9;
			minas = 10;
			break;
		case 3:
			tamanho = 16;
			minas = 40;
			break;
		case 4:
			tamanho = 22;
			minas = 100;
			break;
		case 5:
			tamanho = 34;
			minas = 250;
			break;
	}
	char mapa[tamanho][tamanho], mapa2[tamanho][tamanho];
	gerar(tamanho, mapa, minas);
	for (int ln = 0; ln < tamanho; ln++) {
		for (int col = 0; col < tamanho; col++) {
			mapa2[ln][col] = mapa[ln][col];
		}
	}
	int fj = 0, selecln, seleccol;
	int info[4] = {0, minas, 0, tamanho * tamanho};
	system("cls");
	while (!fj) {
		exibir(tamanho, mapa, mapa2);
		printf("\nO que deseja fazer?\n");
		cmd = getch();
		if (cmd == 'D' || cmd == 'd' || cmd == 'V' || cmd == 'v' || cmd == 'A' || cmd == 'a') {
			printf("Digite as coordenadas.\n");
			scanf("%d %d", &selecln, &seleccol);
		}
		system("cls");
		int tembombas = 0;
		switch (cmd) {
			case 'D': case 'd':
				if (pos_valida(tamanho, selecln, seleccol)) {
					tembombas = descobrir(tamanho, mapa2, selecln, seleccol);
					info[0]++;
				} else {
					printf("Até parece que eu vou te deixar ver fora do mapa.\n");
				}
				break;
			case 'V': case 'v':
				if (pos_valida(tamanho, selecln, seleccol)) {
					mapa[selecln][seleccol] = sinalizar_v(tamanho, mapa, mapa2, selecln, seleccol);
					info[0]++;
				} else {
					printf("Não há motivo para colocar uma bandeira fora do mapa!\n");
				}
				break;
			case 'A': case 'a':
				if (pos_valida(tamanho, selecln, seleccol)) {
					mapa[selecln][seleccol] = sinalizar_a(tamanho, mapa, mapa2, selecln, seleccol);
					info[0]++;
				} else {
					printf("Por que você está em dúvida se tem ou não uma bomba em uma posição que enm existe?\n");
				}
				break;
			case 'I': case 'i':
				inform(info, seed);
				system("cls");
				break;
			case 'H': case 'h':
				ajuda();
				system("cls");
				break;
			default:
				printf("ERRO! Comando não reconhecido. Tente novamente.\n");
		}
		calcular_info(info, minas, tamanho, mapa, mapa2);
		if (vitoria(info, minas)) {
			fj = !fj;
			tela_vitoria(tamanho, mapa, mapa2);
		}
		if (tembombas) {
			fj = !fj;
			tela_derrota(tamanho, mapa, mapa2);
		}
		while (getchar() != '\n');
	}
	printf("\nFIM DE JOGO!\n");
	system("pause");
	return 0;
}
