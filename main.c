#include <stdio.h>

const int tableSize = 128;
char* hashTable[tableSize];

int calculateIndex(char* key) {
  // Calculate some hash. Binary shift of key's number representation for example
  int hash = *(int*)key >> 2;
  // Modulo tableSize makes sure index fits into array's range
  return hash % tableSize;
}

void insert(char* key, char* value) {
  hashTable[calculateIndex(key)] = value;
}

char* find(char* key) {
  return hashTable[calculateIndex(key)];
}

int main() {
  insert("first", "bin");
  insert("second", "bon");
  insert("first", "bun");

  printf("Found: %s\n", find("second"));

  return 0;
}
