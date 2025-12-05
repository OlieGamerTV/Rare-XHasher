// rarehasher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>
#include "AssetCommons.h"

int main(int argc, char* argv[])
{
	if (argc == 1) {
		
		printf("Usage: rarehasher -base/-typed [-verbose] <inFile>\n");
		printf("       -base        -> Calculates a hash from a provided string using the algorithm for Grabbed by the Ghoulies and Viva Pinata.\n");
		printf("       -typed       -> Calculates a hash from a provided string using the algorithm for Banjo-Kazooie: Nuts & Bolts and Kinect Sports.\n");
		printf("\n");
		printf("       -verbose     -> Optional parameter, prints out extra information when generating a hash.\n");

		return 0;
	}

	if (strcmp(argv[1], "-base") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_Base(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_Base(argv[2]);

		return 0;
	}
	else if (strcmp(argv[1], "-typed") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_Typed(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_Typed(argv[2]);

		return 0;
	}
	
	return 0;
}
