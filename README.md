# PUBGDL
Decrypts memory within PUBG using special black magic techniques
  
# USAGE
Usage of this library is up to you. You will have to implement it with whatever technique for read/write you have available.  
  
The test.cpp file includes a test you can run, that shows decrypting of a EncryptedBlock that I've pre-dumped from memory, and stored in a static buffer.

## EXAMPLE CODE
```
#include "stdafx.h"
#include "decrypt.h"
#include <iostream>

int main() {
	/* retrieve the block by reading in an offset such as UWorld */
	EncryptedBlock *block = NULL;

	/* initialize the decryption context, very important! */
	init_decryption();

	/* get a handle to the real pointer via decryption! */
	uint64_t decrypted_ptr = decrypt_ptr(block);

	std::cout << "Decrypted: 0x" << std::hex << decrypted_ptr << std::endl;
	std::cin.get();
	return 0;
}
```

## DISCLAIMER
I'll try to keep this up to date, no promises! Keeping this high of quality up to date, while already being busy is difficult. I don't even write my cheats in a native language!
