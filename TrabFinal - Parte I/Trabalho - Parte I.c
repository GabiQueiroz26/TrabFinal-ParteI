#include <stdio.h>
#include <stdlib.h>

int imagemCinza() {
	int linhas, colunas, vmax;
			int i, j, k, n;
			char buffer[250];
			FILE *origem;
			FILE *destino;
			
			origem = fopen("dog.ppm", "r");
			destino = fopen("dogCinza.ppm", "w");
	
			if(origem == NULL){
				printf("Erro ao abrir o arquivo.");
				return 1;
			} else {
				fgets(buffer, 250, origem); //P3
				fgets(buffer, 250, origem); //Comentario
				fscanf(origem, "%d %d", &colunas, &linhas);
				fscanf(origem, "%d", &vmax);
				int matriz[linhas][colunas][3];
		
			fprintf(destino, "P3\n");
			fprintf(destino, "#Feito por Gabriela\n");
			fprintf(destino, "%d %d\n", colunas, linhas);
			fprintf(destino, "%d\n", vmax);
		
			for(i = 0; i < linhas; i++){
				for(j = 0; j < colunas; j++){
					n = 0;
					for(k = 0; k < 3; k++){
						fscanf(origem, "%d", &matriz[i][j][k]);
						n = n + matriz[i][j][k];
					}
						n = n / 3;
						fprintf(destino, "%d %d %d ", n, n, n);
					}
				}
			}
				fclose(origem);
				fclose(destino);
				return 0;
}

int imagemHorizontal() {
			int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
		
			origem = fopen("dog.ppm", "r");
			destino = fopen("dogEspelhado.ppm", "w");
    

    		char buffer[250], tipo;
			fgets(buffer, 250, origem);
			tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            for (k = 0; k < 3; k++) {
		            fscanf(origem, "%d", &matriz[i][j][k]);
		            }
		        }
		        }
		    } else if(tipo == 2) {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            fscanf(origem, "%d", &n);
		            for (k = 0; k < 3; k++) {
		            matriz[i][j][k] = n;
		            }
		        }
		        }
		    }
		
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas, linhas);
		    fprintf(destino, "%d\n", vmax);
		
		    for(i = 0; i < linhas; i++){
		        for(j = colunas -1 ; j >= 0; j--){
		            for(k = 0; k < 3; k++){
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		    }
		
		    fclose(origem);
		    fclose(destino);
		
		    return 0;
}

int imagemVertical() {
	int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
			
			origem = fopen("dog.ppm", "r");
			destino = fopen("dogVirado.ppm", "w");
    

		    char buffer[250], tipo;
			fgets(buffer, 250, origem);
			tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
		    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            for (k = 0; k < 3; k++) {
		            fscanf(origem, "%d", &matriz[i][j][k]);
		            }
		        }
		        }
		    } else if(tipo == 2) {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            fscanf(origem, "%d", &n);
		            for (k = 0; k < 3; k++) {
		            matriz[i][j][k] = n;
		            }
		        }
		        }
		    }
		
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas, linhas);
		    fprintf(destino, "%d\n", vmax);
		
		    for(i = linhas -1; i >= 0; i--){
		        for(j = 0 ; j < colunas; j++){
		            for(k = 0; k < 3; k++){
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		    }
		
		    fclose(origem);
		    fclose(destino);
		
		    return 0;
}

int imagemEsqDireita() {
		int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
			FILE *destino2;
			
			origem = fopen("dog.ppm", "r");
		    destino = fopen("dogEsquerda.ppm", "w");
		    destino2 = fopen("dogDireita.ppm", "w");
		    
		    char buffer[250], tipo;
		    fgets(buffer, 250, origem);
		    tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
		    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                for (k = 0; k < 3; k++) {
		                    fscanf(origem, "%d", &matriz[i][j][k]);
		                }
		            }
		        }
		    } else if(tipo == '2') { // Corrigido para tipo ser um caractere
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                fscanf(origem, "%d", &n);
		                for (k = 0; k < 3; k++) {
		                    matriz[i][j][k] = n;
		                }
		            }
		        }
		    }
		    
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas / 2, linhas);
		    fprintf(destino, "%d\n", vmax);
		    
		    fprintf(destino2, "P3\n");
		    fprintf(destino2, "#Feito por Gabriela\n");
		    fprintf(destino2, "%d %d\n", colunas - colunas / 2, linhas);
		    fprintf(destino2, "%d\n", vmax);
		    
		    for(i = 0; i < linhas; i++) {
		        for(j = 0; j < colunas / 2; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		        
		        for(j = colunas / 2; j < colunas; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino2, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino2, "\n");
		    }
		    
		    fclose(origem);
		    fclose(destino);
		    fclose(destino2);
		    
		    return 0;
}

int imagemSupInferior() {
				int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
			FILE *destino2;
			
			origem = fopen("dog.ppm", "r");
		    destino = fopen("dogSuperior.ppm", "w");
		    destino2 = fopen("dogInferior.ppm", "w");
		    
		    char buffer[250], tipo;
		    fgets(buffer, 250, origem);
		    tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
		    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                for (k = 0; k < 3; k++) {
		                    fscanf(origem, "%d", &matriz[i][j][k]);
		                }
		            }
		        }
		    } else if(tipo == '2') {
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                fscanf(origem, "%d", &n);
		                for (k = 0; k < 3; k++) {
		                    matriz[i][j][k] = n;
		                }
		            }
		        }
		    }
		    
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas, linhas / 2); // Alterado para linhas / 2
		    fprintf(destino, "%d\n", vmax);
		    
		    fprintf(destino2, "P3\n");
		    fprintf(destino2, "#Feito por Gabriela\n");
		    fprintf(destino2, "%d %d\n", colunas, linhas - linhas / 2); // Alterado para linhas - linhas / 2
		    fprintf(destino2, "%d\n", vmax);
		    
		    for(i = 0; i < linhas / 2; i++) { // Alterado para linhas / 2
		        for(j = 0; j < colunas; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		    }
		    
		    for(i = linhas / 2; i < linhas; i++) { // Alterado para linhas / 2
		        for(j = 0; j < colunas; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino2, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino2, "\n");
		    }
		    
		    fclose(origem);
		    fclose(destino);
		    fclose(destino2);
		    
		    return 0;
}


int main() {
	int menu, invalido;

do{

	printf("-----------------------------------------------------------------------\n");
	printf("|                    Menu para tratamento de imagens                  |\n");
	printf("-----------------------------------------------------------------------\n");
	printf("1 para converter imagem colorida para escala de cinza\n");
	printf("2 para espelhar imagem horizontalmente\n");
	printf("3 para espelhar imagem verticalmente\n");
	printf("4 para dividir imagem em dois arquivos(metade esquerda, metade direita)\n");
	printf("5 para dividir imagem em dois arquivos(metade superior, metade inferior)\n");
	printf("0 para sair\n");
	
	scanf("%d", &menu);
	
	switch(menu) {
		case 1: 
			imagemCinza();
			printf("Pronto! Sua imagem foi gerada, va ate a pasta do arquivo e confira!\n");
			break;
				
		case 2: 
			imagemHorizontal();
			printf("Pronto! Sua imagem foi gerada, va ate a pasta do arquivo e confira!\n");
		    break;
		
		case 3:
			imagemVertical();
			printf("Pronto! Sua imagem foi gerada, va ate a pasta do arquivo e confira!\n");
		    break;
		    
		case 4:
			imagemEsqDireita();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
		    break;
		
		case 5:
			imagemSupInferior();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
		    break;
		default:
			printf("Saindo do programa\n");
			break;
	}
} while (menu != 0);
}

	
