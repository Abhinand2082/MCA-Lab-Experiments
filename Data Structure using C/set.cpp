#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* bits;
    int size;
} BitSet;

BitSet* createBitSet(int size) {
    BitSet* set = (BitSet*)malloc(sizeof(BitSet));
    set->size = size;
    set->bits = (char*)malloc((size + 7) / 8);
    memset(set->bits, 0, (size + 7) / 8);
    return set;
}

void add(BitSet* set, int element) {
    set->bits[element / 8] |= (1 << (element % 8));
}

int contains(BitSet* set, int element) {
    return (set->bits[element / 8] & (1 << (element % 8))) != 0;
}

BitSet* unionSet(BitSet* set1, BitSet* set2) {
    int maxSize = (set1->size > set2->size) ? set1->size : set2->size;
    BitSet* newSet = createBitSet(maxSize);

    for (int i = 0; i < (maxSize + 7) / 8; i++) {
        newSet->bits[i] = set1->bits[i] | set2->bits[i];
    }

    return newSet;
}

BitSet* intersectionSet(BitSet* set1, BitSet* set2) {
    int minSize = (set1->size < set2->size) ? set1->size : set2->size;
    BitSet* newSet = createBitSet(minSize);

    for (int i = 0; i < (minSize + 7) / 8; i++) {
        newSet->bits[i] = set1->bits[i] & set2->bits[i];
    }

    return newSet;
}

BitSet* differenceSet(BitSet* set1, BitSet* set2) {
    int maxSize = (set1->size > set2->size) ? set1->size : set2->size;
    BitSet* newSet = createBitSet(maxSize);

    for (int i = 0; i < (maxSize + 7) / 8; i++) {
        newSet->bits[i] = set1->bits[i] & ~(set2->bits[i]);
    }

    return newSet;
}

void printSet(BitSet* set) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        if (contains(set, i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    BitSet* set1 = createBitSet(100);
    add(set1, 1);
    add(set1, 3);
    add(set1, 5);

    BitSet* set2 = createBitSet(100);
    add(set2, 3);
    add(set2, 5);
    add(set2, 7);

    BitSet* unionSetResult = unionSet(set1, set2);
    BitSet* intersectionSetResult = intersectionSet(set1, set2);
    BitSet* differenceSetResult = differenceSet(set1, set2);

    printf("Set 1: ");
    printSet(set1);
    printf("Set 2: ");
    printSet(set2);
    printf("Union: ");
    printSet(unionSetResult);
    printf("Intersection: ");
    printSet(intersectionSetResult);
    printf("Difference: ");
    printSet(differenceSetResult);

    free(set1->bits);
    free(set1);
    free(set2->bits);
    free(set2);
    free(unionSetResult->bits);
    free(unionSetResult);
    free(intersectionSetResult->bits);
    free(intersectionSetResult);
    free(differenceSetResult->bits);
    free(differenceSetResult);

    return 0;
}