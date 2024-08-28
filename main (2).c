#include <stdio.h>// Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão de funções gerais, como alocação de memória e controle de processos
#include <locale.h>// Inclui a biblioteca para manipulação de configurações regionais, como a localidade (ex: idioma)
#include "listaEstatica.h" // Inclui o cabeçalho "listaEstatica.h", onde as funções da agenda (como Menuagenda) são declaradas

int main() {
	setlocale(LC_ALL, "Portuguese");// Configura a localidade para o idioma português, garantindo que caracteres especiais e formatação numérica sejam corretamente exibidos
		Menuagenda(); // Chama a função Menuagenda, que exibe o menu principal e executa as ações da agenda
}
