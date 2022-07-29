#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char* key;
	char* value;
} ht_item;

typedef struct {
	int size;
	int count;
	ht_item** items;
} ht_hash_table;

static ht_item* ht_init_item(const char* _key, const char* _value);

static ht_hash_table* ht_init_sized_hash_tb(const int sizebased);

ht_hash_table* ht_init_hash_tb();

void ht_clear_item(ht_item* i);

void ht_clear_hash_tb(ht_hash_table* ht);

static int ht_hash(const char* st, const int a, const int mod);

int alg_hash_calc(int i, char s, int ln, int a);

static int ht_get_hash(const char* c, const int num, const int att);

void ht_insert(ht_hash_table* ht, const char* _key, const char* _value);

char* ht_search(ht_hash_table* ht, const char* _key);

void ht_delete(ht_hash_table* ht, const char* _key);