#include "stdafx.h"
#include "native_utils.h"

int32_t ubyte0(int32_t i) {
	return i & 0xFF;
}

int32_t ubyte1(int32_t i) {
	return (i >> 8) & 0xFF;
}

int32_t ubyte2(int32_t i) {
	return (i >> 16) & 0xFF;
}

int32_t ubyte3(int32_t i) {
	return (i >> 24) & 0xFF;
}

int32_t word0(int64_t l) {
	return (l >> 0) & 0xFFFF;
}