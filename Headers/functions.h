#pragma once
#include <Windows.h>

void usage();
void verificarMZ(char argv[]);
void printDos(IMAGE_DOS_HEADER* myDosHeader);
void printFileHeader(IMAGE_FILE_HEADER* myFileHeader);
void printOptionalHeader64(IMAGE_OPTIONAL_HEADER64* myOptionalHeader);
