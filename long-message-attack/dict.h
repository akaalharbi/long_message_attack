#ifndef DICT_LINEAR_PROBING
#define DICT_LINEAR_PROBING


#include "types.h"
// #include "sha256.h" // dict_key 
#include <stddef.h>  // size_t
#include <stdint.h> // uintXY_t
#include <stdlib.h>  // malloc
#include <string.h> // memcpy
#include <stdio.h>  // printf
#include "types.h" // dict_key union type 
#include "util/util_char_arrays.h" // cmp_arrays
#include "shared.h"
///-----------------------------------------------------///
///                  data structure                     ///
///-----------------------------------------------------///

typedef struct {
  /// a slot can hold one element at most!
  /// This implementaion suggest that slot1's key and slot2's key are
  /// NOT next to each other in the memory. Durint the dictionary init
  /// we will ensure that they are contagious in the memory. 
  /// UPDATE: dictionary contains a copy of all its data
  
  
  dict_key key; // the key has a fixed length given at the beginning of the run
  size_t value; // if value==0 then its an empty slot. Any element added to dict
                // need to be incremented by one.
  // no need for this
  // int is_occupied; // 1 bit. 0 if it is empty, 1 if slot has an element
  
} slot;


typedef struct {
  UINT nslots; // number of elements  in the dictionary
  slot* slots; // == slot slots[nslots] but on the heap
} dict;






//-----------------------------------------------------//
//                    functions                        //
//-----------------------------------------------------//
slot *slot_new();
dict *dict_new(size_t nslots, size_t key_size);
void dict_add_element_to(dict* d, dict_key* key,size_t value, size_t key_size);
int dict_has_key(dict* d, dict_key* key, size_t key_size);
size_t dict_get_value(dict* d, dict_key* key, size_t key_size);
void dict_print(dict *d, size_t key_size);

#endif
