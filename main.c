#include <stdio.h>
#include <string.h>

const int tableSize = 128;
struct Entry* hashTable[tableSize] = {};

struct Entry
{
  char key[32];
  char value[32];
  struct Entry* next;
};

int calculateIndex(char* key) {
  // Calculate some hash. Binary shift of key's number representation for example
  int hash = *(int*)key >> 2;
  // Modulo tableSize makes sure index fits into array's range
  return hash % tableSize;
}

void insert(struct Entry* entry) {
  int i = calculateIndex(entry->key);

  if (hashTable[i] != NULL) {
    entry->next = hashTable[i];
  }
  hashTable[i] = entry;
}

char* find(char* key) {
  struct Entry* entry = hashTable[calculateIndex(key)];

  while(entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }

    entry = entry->next;
  }

  return "";
}

int main() {
  insert(&(struct Entry){ "first", "bin" });
  insert(&(struct Entry){ "second", "bon" });
  insert(&(struct Entry){ "third", "bun" });

  printf("Found: %s\n", find("second"));

  return 0;
}
