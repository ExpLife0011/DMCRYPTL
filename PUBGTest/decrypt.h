#pragma once
#include <cstdint>

struct EncryptedBlock {
	int64_t data[48];
};

void init_decryption();

uint64_t decrypt_ptr(EncryptedBlock *block);