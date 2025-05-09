#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Headers/functions.h"
#include <stdbool.h>

// Por hora apenas binários 64 bits devem ser utilizados como exemplo
// O objetivo é focar em aprender conceitos de C e não escrever um software para uso comercial 100% funcional

int main(int argc, char* argv[]) {
	char mz[2] = { '0' };
	DWORD signature = 0;


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
	// printDos(&dosHeader);

	fseek(filePointer, dosHeader.e_lfanew, SEEK_SET);
	fread(&signature, sizeof(DWORD), 1, filePointer);

	IMAGE_FILE_HEADER fileHeader;
	fread(&fileHeader, sizeof(fileHeader), 1, filePointer);

	// printFileHeader(&fileHeader);


	if (fileHeader.Machine != 0x8664) {
		printf("Arquivo PE não compativel com 64 Bits, finalizando execução\n");
		exit(1);
	}

	IMAGE_OPTIONAL_HEADER64 optionalHeader;
	fread(&optionalHeader, sizeof(optionalHeader), 1, filePointer);


	return 0;
}