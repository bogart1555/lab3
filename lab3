#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include "myendian.h"


using namespace std;

class RunLengthEncodingArchiver {
public:
	void compress(char *filenameIn, char *filenameOut) {
		FILE *fo = fopen(filenameOut, "wb");
		FILE *fi = fopen(filenameIn, "rb");

		uint16_t count = 0;

		int last, c;
		while ((c = fgetc(fi)) != EOF) {
			if (c == last) {
				count++;
				continue;
			}
			PutBE16(count, fo);
			fputc(last, fo);
			last = c;
			count = 1;
		}
		PutBE16(count, fo);
		fputc(last, fo);

		fclose(fi);
		fclose(fo);
	}

	void decompress(char *filenameIn, char *filenameOut) {
		FILE *fo = fopen(filenameOut, "wb");
		FILE *fi = fopen(filenameIn, "rb");

		while (true) {
			uint16_t count = GetBE16(fi);
			if (feof(fi)) {
				break;
			}
			int c = fgetc(fi);
			for (int i = 0; i < count; i++) {
				fputc(c, fo);
			}
		}

		fclose(fi);
		fclose(fo);
	}
};

int main(int argc, char **argv) {
	cout << "hello world" << endl;


	// --- удалить при запуске на компьютере ---
	//argc = 4;
	//argv = new char *[argc];
	// argv[1] = (char *) "--compress";
	// argv[2] = (char *) "output.rle";
	// argv[3] = (char *) "input.bmp";
	//argv[1] = (char *) "--decompress";
	//argv[2] = (char *) "output.rle";
	//argv[3] = (char *) "input2.bmp";
	// -----------------------------------------


	if (argc != 4) {
		cout << "usage: " << argv[0];
		cout << " <--compress|--decompress> <input file> <output file>";
		cout << endl;
		return 0;
	}

	RunLengthEncodingArchiver rle;
	if (!strcmp(argv[1], "--compress")) {
		rle.compress(argv[3], argv[2]);
		cout << "Done." << endl;
	}
	else if (!strcmp(argv[1], "--decompress")) {
		rle.decompress(argv[2], argv[3]);
		cout << "Done." << endl;
	}
	else {
		cout << "usage: " << argv[0];
		cout << " <--compress|--decompress> <input file> <output file>";
		cout << endl;
	}
	system("pause");
	return 0;
}
