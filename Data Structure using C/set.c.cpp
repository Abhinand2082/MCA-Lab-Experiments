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
    int size1, size2;

    printf("Enter the size of Set 1: ");
    scanf("%d", &size1);
    BitSet* set1 = createBitSet(size1);

    printf("Enter elements of Set 1 (space-separated, -1 to end): ");
    int element;
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        add(set1, element);
    }

    printf("Enter the size of Set 2: ");
    scanf("%d", &size2);
    BitSet* set2 = createBitSet(size2);

    printf("Enter elements of Set 2 (space-separated, -1 to end): ");
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        add(set2, element);
    }

    BitSet* unionSetResult = unionSet(set1, set2);
    BitSet* intersectionSetResult = intersectionSet(set1, set2);
    BitSet* differenceSetResult = differenceSet(set1, set2);

    printf("\nSet 1: ");
    printSet(set1);
    printf("Set 2: ");
    printSet(set2);
    printf("Union: ");
    printSet(unionSetResult);
    printf("Intersection: ");
    printSet(intersectionSetResult);
    printf("Difference: ");
    printSet(differenceSetResult);

    // Free allocated memory
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