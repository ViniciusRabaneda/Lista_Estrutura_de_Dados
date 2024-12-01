#include <stdio.h>
#include <stdlib.h>

//Questao 6
typedef struct voo {
	int numeroVoo;
	int dataVoo;
	int hora;
	int min;
	int aeroportoSaida;
	int aeroportoChegada;
	int rotaId;
	float tempoEstimado;
	int passageiros;
	struct voo* proximo;
} Voo;

Voo* criarVoo(int numero, int data, int hora, int min, int saida, int chegada, int rota, float tempo, int passageiros) {
	Voo* novoVoo = (Voo*)malloc(sizeof(Voo));
	if (novoVoo) {
		novoVoo->numeroVoo = numero;
		novoVoo->dataVoo = data;
		novoVoo->hora = hora;
		novoVoo->min = min;
		novoVoo->aeroportoSaida = saida;
		novoVoo->aeroportoChegada = chegada;
		novoVoo->rotaId = rota;
		novoVoo->tempoEstimado = tempo;
		novoVoo->passageiros = passageiros;
		novoVoo->proximo = NULL;
	}
	return novoVoo;
}

//Questao 7
void cadastrarVoo(Voo** lista, Voo* novoVoo) {
	novoVoo->proximo = *lista;
	*lista = novoVoo;
}

//Questao 8
Voo* consultaVoo(Voo* lista, int numeroVoo) {
	Voo* atual = lista;
	while (atual != NULL) {
		if (atual->numeroVoo == numeroVoo) {
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
}

//Questao 9
int removeVoo(Voo** lista, int numeroVoo) {
	Voo* atual = *lista;
	Voo* anterior = NULL;
	while (atual != NULL) {
		if (atual->numeroVoo == numeroVoo) {
			if (anterior == NULL) {
				*lista = atual->proximo;
			} else {
				anterior->proximo = atual->proximo;
			}
			free(atual);
			return 1;
		}
		anterior = atual;
		atual = atual->proximo;
	}
	return 0;
}


int main() {
	Voo* listaVoos = NULL;

	cadastrarVoo(&listaVoos, criarVoo(106, 1, 14, 30, 1, 2, 100, 1.5, 150));
	cadastrarVoo(&listaVoos, criarVoo(4433, 3, 9, 45, 3, 4, 101, 2.0, 120));
	cadastrarVoo(&listaVoos, criarVoo(2083, 5, 18, 15, 5, 6, 102, 2.5, 180));

	int numeroConsulta = 4433;
	Voo* consulta = consultaVoo(listaVoos, numeroConsulta);
	if (consulta) {
		printf("Consulta Voo %d:\n", numeroConsulta);
		printf("Numero do Voo: %d\n", consulta->numeroVoo);
		printf("Data do Voo: %d\n", consulta->dataVoo);
		printf("Horario do Voo: %02d:%02d\n", consulta->hora, consulta->min);
		printf("Aeroporto de Saida: %d\n", consulta->aeroportoSaida);
		printf("Aeroporto de Chegada: %d\n", consulta->aeroportoChegada);
		printf("Rota ID: %d\n", consulta->rotaId);
		printf("Tempo Estimado de Voo: %.2f\n", consulta->tempoEstimado);
		printf("Passageiros a Bordo: %d\n", consulta->passageiros);
		printf("\n");
	} else {
		printf("Voo %d nao encontrado.\n", numeroConsulta);
	}

	int numeroRemocao = 106;
	if (removeVoo(&listaVoos, numeroRemocao)) {
		printf("Voo %d removido com sucesso.\n", numeroRemocao);
	} else {
		printf("Voo %d naoo encontrado.\n", numeroRemocao);
	}
	return 0;
}