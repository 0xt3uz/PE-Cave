#pragma once
#include <Windows.h>

void usage();
void verificarMZ(char argv[]);
void printDos(IMAGE_DOS_HEADER* myDosHeader);