#pragma once
#include <cstdint>

class DynTable {
private:
	uint32_t table[2048];

public:
	void generate(int32_t rotator, int32_t(&decrypt_offsets)[7]);
	uint32_t get(uint32_t idx);
};