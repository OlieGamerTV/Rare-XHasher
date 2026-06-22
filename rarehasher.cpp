// rarehasher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string.h>
#include <typeinfo>
#include <iostream>
#include "AssetCommons.h"

int main(int argc, char* argv[])
{
	if (argc == 1) {
		
		printf("Usage: rarehasher <hashOption> [-verbose] <inFile>\n");
		printf("Base Options:\n");
		printf("       -base        -> Calculates a hash using the algorithm for Grabbed by the Ghoulies and Viva Pinata.\n");
		printf("       -dol         -> Calculates a hash using the algorithm for Kameo: Elements of Power.\n");
		printf("       -dark        -> Calculates a hash using the algorithm for Perfect Dark Zero.\n");
		printf("       -typed       -> Calculates a hash using the algorithm for Banjo-Kazooie: Nuts & Bolts and Kinect Sports.\n");
		printf("\n");
		printf("Misc. Options:\n");
		printf("       -locHash     -> Calculates a hash used for the R1 localization text banks.\n");
		printf("       -verbose     -> Optional parameter, prints out extra information when generating a hash.\n");

		return 0;
	}

	if (strcmp(argv[1], "-locHash") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}

		unsigned short hash = locHashElfHash16(argv[2]);

		std::cout << "LOC Hash : " << hash << "\n";

		return 0;
	}

	if (strcmp(argv[1], "-base") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_Base(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_Base(argv[2]);

		return 0;
	}
	else if (strcmp(argv[1], "-dol") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_Dolphin(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_Dolphin(argv[2]);

		printf("Relevant Structures:\n");
		printf("                    Uberroot\\%08X.lvl\n", hash);

		return 0;
	}
	else if (strcmp(argv[1], "-dark") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_Dark(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_Dark(argv[2]);

		printf("Relevant Structures:\n");
		printf("                    Uberroot\\PackageData\\%u.pkg\n", hash);

		return 0;
	}
	else if (strcmp(argv[1], "-base_ext") == 0) {
		std::cout << "WARNING: INCOMPLETE.\n";
		if (argc < 3) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_BaseExt(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_BaseExt(argv[2]);

		return 0;
	}
	else if (strcmp(argv[1], "-typed") == 0) {
		if (argc < 3) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}

		if (strcmp(argv[2], "-verbose") == 0 && argc < 4) {
			std::cout << "No inFile was provided.\n";
			return -1;
		}
		if (strcmp(argv[2], "-verbose") == 0 && argc >= 4) {
			unsigned int hash = assetIdGetHash_Typed(argv[3], true);

			return 0;
		}

		unsigned int hash = assetIdGetHash_Typed(argv[2]);

		if (hash >> 24 == 0x4F || hash >> 24 == 0x50) {
			printf("Relevant Structures (N&B):\n");
			printf("-       Uberroot\\Bundle\\%02x\\%06x\n", hash >> 24, hash & 0x00FFFFFF);
		}

		if (hash >> 24 == 0x11 || hash >> 24 == 0x36) {
			printf("Relevant Structures (N&B):\n");
			printf("-       Uberroot\\Debug\\%02x\\%02x\\%02x\\%02x\n", hash >> 24, (hash >> 16) & 0xFF, (hash >> 8) & 0xFF, hash & 0xFF);
		}

		return 0;
	}
	
	return 0;
}
