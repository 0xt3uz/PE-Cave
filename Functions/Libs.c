#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void usage() {
	printf("Usage: ./pe-cave pe-file.exe");
	exit(1);
}

void verificarMZ(char argv[]) {
	if (argv[0] != 0x4D && argv[1] != 0x5A) {
		printf("Arquivo PE invalido\n");
		exit(1);
	}
}

void printDos(IMAGE_DOS_HEADER* myDosHeader) {
	printf("e_magic: 0x%X\n", myDosHeader->e_magic);
	printf("e_cblp: %u\n", myDosHeader->e_cblp);
	printf("e_cp: %u\n", myDosHeader->e_cp);
	printf("e_crlc: %u\n", myDosHeader->e_crlc);
	printf("e_cparhdr: %u\n", myDosHeader->e_cparhdr);
	printf("e_minalloc: %u\n", myDosHeader->e_minalloc);
	printf("e_maxalloc: %u\n", myDosHeader->e_maxalloc);
	printf("e_ss: %u\n", myDosHeader->e_ss);
	printf("e_sp: %u\n", myDosHeader->e_sp);
	printf("e_csum: %u\n", myDosHeader->e_csum);
	printf("e_ip: %u\n", myDosHeader->e_ip);
	printf("e_cs: %u\n", myDosHeader->e_cs);
	printf("e_lfarlc: %u\n", myDosHeader->e_lfarlc);
	printf("e_ovno: %u\n", myDosHeader->e_ovno);

	//for (int i = 0; i < 4; i++) {
	//	printf("e_res[%d]: %u\n", i, myDosHeader->e_res[i]);
	//}

	printf("e_oemid: %u\n", myDosHeader->e_oemid);
	printf("e_oeminfo: %u\n", myDosHeader->e_oeminfo);

	//for (int i = 0; i < 10; i++) {
	//	printf("e_res2[%d]: %u\n", i, myDosHeader->e_res2[i]);
	//}

	printf("e_lfanew: 0x%X\n", myDosHeader->e_lfanew);
}