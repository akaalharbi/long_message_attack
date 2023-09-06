
#ifndef SHA256_INTEL_AVX2
#define SHA256_INTEL_AVX2
#include <stdint.h>



uint32_t *sha256_multiple_oct(uint8_t msg[16][64]);
uint32_t *sha256_multiple_oct_tr(uint8_t msg[16][64],
                                 uint32_t tr_states[16 * 8]);

#endif


#ifndef SHA256_INTEL_AVX512
#define SHA256_INTEL_AVX512



uint32_t *sha256_multiple_x16(uint8_t msg[16][64]);

uint32_t *sha256_multiple_x16_tr(uint8_t msg[16][64],
                                 uint32_t tr_states[16 * 8], int inited);


#endif