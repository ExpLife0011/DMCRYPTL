#include "stdafx.h"
#include "native_utils.h"

int ubyte0(int i) {
	return i & 0xFF;
}

int ubyte1(int i) {
	return (i >> 8) & 0xFF;
}

int word4(int64_t l) {
	return (l >> 0) & 0xFFFF;
}