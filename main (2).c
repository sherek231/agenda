#include <stdio.h>// Inclui a biblioteca padr�o de entrada e sa�da
#include <stdlib.h> // Inclui a biblioteca padr�o de fun��es gerais, como aloca��o de mem�ria e controle de processos
#include <locale.h>// Inclui a biblioteca para manipula��o de configura��es regionais, como a localidade (ex: idioma)
#include "listaEstatica.h" // Inclui o cabe�alho "listaEstatica.h", onde as fun��es da agenda (como Menuagenda) s�o declaradas

int main() {
	setlocale(LC_ALL, "Portuguese");// Configura a localidade para o idioma portugu�s, garantindo que caracteres especiais e formata��o num�rica sejam corretamente exibidos
		Menuagenda(); // Chama a fun��o Menuagenda, que exibe o menu principal e executa as a��es da agenda
}
