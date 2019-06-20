#ifndef MYENDIAN_H
#define MYENDIAN_H

#include <cstdio>
#include <cstdint>

uint16_t GetBE16(FILE* fp) {
	uint16_t ret;
	ret = fgetc(fp) << 8;
	ret |= fgetc(fp);
	return ret;
}

uint16_t GetLE16(FILE* fp) {
	uint16_t ret;
	ret = fgetc(fp);
	ret |= fgetc(fp) << 8;
	return ret;
}

uint32_t GetBE32(FILE* fp) {
	uint32_t ret;
	ret = fgetc(fp) << 24;
	ret |= fgetc(fp) << 16;
	ret |= fgetc(fp) << 8;
	ret |= fgetc(fp);
	return ret;
}

uint32_t GetLE32(FILE* fp) {
	uint32_t ret;
	ret = fgetc(fp);
	ret |= fgetc(fp) << 8;
	ret |= fgetc(fp) << 16;
	ret |= fgetc(fp) << 24;
	return ret;
}

void PutBE16(uint16_t d, FILE* fp) {
	fputc((d >> 8) & 0xFF, fp);
	fputc((d) & 0xFF, fp);
}

void PutLE16(uint16_t d, FILE* fp) {
	fputc((d) & 0xFF, fp);
	fputc((d >> 8) & 0xFF, fp);
}

void PutBE32(uint32_t d, FILE* fp) {
	fputc((d >> 24) & 0xFF, fp);
	fputc((d >> 16) & 0xFF, fp);
	fputc((d >> 8) & 0xFF, fp);
	fputc((d) & 0xFF, fp);
}

void PutLE32(uint32_t d, FILE* fp) {
	fputc((d) & 0xFF, fp);
	fputc((d >> 8) & 0xFF, fp);
	fputc((d >> 16) & 0xFF, fp);
	fputc((d >> 24) & 0xFF, fp);
}

#endif
