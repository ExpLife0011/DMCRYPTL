#include "stdafx.h"
#include "table.h"

void DynTable::generate(int rotator, int (&decrypt_offsets)[7]) {
	for (uint32_t i = 0; i < 0x100; i++) {
		uint32_t tmp = i;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		tmp >>= 1;
		if ((tmp & 1) != 0)
			tmp ^= rotator;

		this->table[i] = tmp >> 1;
	}

	uint32_t off = 0x200;
	for (int i = 0; i < 0x100; i++) {
		uint32_t tmp = this->table[off - 0x200];

		off += 1;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[0]] = tmp;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[1]] = tmp;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[2]] = tmp;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[3]] = tmp;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[4]] = tmp;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[5]] = tmp;

		tmp = (tmp >> 8) ^ this->table[tmp & 0xFF];
		this->table[off + decrypt_offsets[6]] = tmp;
	}
}

uint32_t DynTable::get(int idx) {
	return this->table[idx];
}