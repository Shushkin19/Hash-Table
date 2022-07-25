#include"hash_table.h"
#include<stdlib.h>
#include<string.h>
#include<math.h>
static ht_item* ht_init_item(const char* _key, const char* _value) {
	ht_item* ht = (ht_item*)malloc(sizeof(ht_item));
	ht->key = _strdup(_key); /// !!!
	ht->value = _strdup(_value);
	return ht;
}


ht_hash_table* ht_init_hash_tb() {
	ht_hash_table* hs_t = (ht_hash_table*)malloc(sizeof(ht_hash_table));
	hs_t->size = 53;
	hs_t->count = 0;
	hs_t->items = (ht_item*)calloc(hs_t->size, sizeof(ht_item*));
	return hs_t;
}

void ht_clear_item(ht_item* i) {
	free(i->key);
	free(i->value);
	free(i);
}

void ht_clear_hash_tb(ht_hash_table* ht) {
	for (int i = 0; i < ht->size; i++) {
		ht_item* it = ht->items[i];
		if (it != NULL) {
			ht_clear_item(it);
		}
	}
	free(ht->items);
	free(ht);
}

int alg_hash_calc(int i, char s, int ln, int a) { /// сделать алгоритм по нормальному распределению
	return (int)pow(a, ln - (i + 1) * s);
}

static int ht_hash(const char* st, const int a, const int mod) {
	int hash = 0;
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		hash += alg_hash_calc(i, st[i], len, a);
		hash %= mod;
	}
	return hash;
}