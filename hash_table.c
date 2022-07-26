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

static int ht_get_hash(const char* c, const int num, const int att) {
	
	/// !!!!!!!!!!!!!!!!!
	const int hash_a = ht_hash(c,HT_PRIME_1, num);

	const int hash_b = ht_hash(c, HT_PRIME_2, num);
	return (hash_a + (att * (hash_b + 1))) % num;
	
}

void ht_insert(ht_hash_table* ht, const char* _key, const char* _value) {
	ht_item* item = ht_init_item(_key, _value);
	int ind = ht_get_hash(item->key, ht->size, 0);
	ht_item* cur_item = ht->items[ind];
	int i = 1;
	while (cur_item != NULL) {
		ind = ht_get_hash(item->key, ht->size, i);
		cur_item = ht->items[ind];
		i++;
	}
	ht->items[ind] = item;
	ht->count++;

}

char* ht_search(ht_hash_table* ht, const char* _key) {


}

void ht_delete(ht_hash_table* ht, const char* _key) {

}