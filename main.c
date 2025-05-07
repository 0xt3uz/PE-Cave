#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Headers/functions.h"

int main(int argc, char* argv[]) {
	char mz[2] = { '0' };

	if (argc < 2) {
		usage();
	}

	// Tenta abrir ao arquivo
	FILE* filePointer = fopen(argv[1], "rb");

	if (!filePointer) {
		printf("Falha ao Abrir o arquivo!\n");
		printf("Erro code: %lu\n", GetLastError());
		return 1;
	} // Valida se o arquivo foi aberto!

	fread(mz, sizeof(char), 2, filePointer);
	verificarMZ(mz);

	// Volta o filePointer para o inicio do arquivo
	// Devido a leitura a cima o ponteiro do arquivo foi mexido
	fseek(filePointer, 0, SEEK_SET);

	IMAGE_DOS_HEADER dosHeader;
	fread(&dosHeader, sizeof(dosHeader), 1, filePointer);

	printDos(&dosHeader);

	return 0;
}