# PUBGDL
Decrypts memory within PUBG using special black magic techniques.  
  
PUBG no longer encrypts memory as of 1/17/2018. I'll keep this repository up temporarily in case of another drastic change in security design.  
  
## NOTES
PUBGDL does not need to RPM for any additional information, only the encrypted data, which you would normally read anyways (only as a pointer instead, whereas it's a EncryptedBlock structure now.)

# USAGE
Usage of this library is up to you. You will have to implement it with whatever technique for read/write you have available.  
  
The test.cpp file includes a test you can run, that shows decrypting of a EncryptedBlock that I've pre-dumped from memory, and stored in a static buffer.

## EXAMPLE CODE
```
#include "stdafx.h"
#include "decrypt.h"
#include <iostream>

struct UWorld { };

int main() {
	/* retrieve the block by reading in an offset such as UWorld */
	EncryptedBlock *block = NULL;

	/* initialize the decryption context, very important! */
	init_decryption();

	/* get a handle to the real pointer via decryption! */
	UWorld *decrypted_ptr = decrypt_ptr<UWorld*>(block);

	std::cout << "Decrypted: 0x" << std::hex << decrypted_ptr << std::endl;
	std::cin.get();
	return 0;
}
```

## DISCLAIMER
I'll try to keep this up to date, no promises! Keeping this high of quality up to date, while already being busy is difficult. I don't even write my cheats in a native language!
