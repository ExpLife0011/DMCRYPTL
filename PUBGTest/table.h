#pragma once
#include <cstdint>

class DynTable {
private:
	uint32_t table[2048];

public:
	void generate(int rotator, int *decrypt_offsets);
	uint32_t get(int idx);
};