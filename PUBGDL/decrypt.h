#pragma once
#include <cstdint>

struct EncryptedBlock {
	int64_t data[48];
};

void init_decryption(void);

uint16_t decrypt_p1(int64_t left, int64_t right);
uint64_t decrypt_p20(int64_t left, int64_t right, uint64_t a, uint64_t b, uint64_t c, uint64_t d_idx);
uint64_t decrypt_p21(int64_t left, int64_t right);
uint64_t decrypt_p22(int64_t left, int64_t right);

template <typename T>
T decrypt_ptr(EncryptedBlock *block) {
	auto a = block->data[decrypt_p21(block->data[44], block->data[45])];
	auto b = decrypt_p22(block->data[46], block->data[47]);
	return (T)(a ^ b);
}