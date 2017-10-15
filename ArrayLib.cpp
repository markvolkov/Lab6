#include <iostream>
#include "ArrayLib.h"

int getShuffledNumber(int* array, int size, int currentIndex, int *numLinesRun) {
    (*numLinesRun)+=4;
    int randomNum = genRandInt(1, size, numLinesRun);
    if (find(array, currentIndex, randomNum) != -1) {
        (*numLinesRun)++;
        return getShuffledNumber(array, size, currentIndex, numLinesRun);
    }
    return randomNum;
}

std::string toStringR(const int *const arrayPtr, const int size, int index, std::string value) {
    if (index > (size - 1)) {
        return value + "}";
    } else if (index == 0) {
        return toStringR(arrayPtr, size, index+1, value + std::to_string(arrayPtr[index]));
    } else {
        return toStringR(arrayPtr, size, index+1, value + ", " + std::to_string(arrayPtr[index]));
    }
}

std::string toString(const int *const arrayPtr, const int size) {
    return toStringR(arrayPtr, size, 0, "{");
}

int findMaxIndexR(const int *const arrayPtr, const int size, int index, int maxIndex) {
    if (index > (size - 1)) {
        return maxIndex;
    } else if (index == 0) {
        return findMaxIndexR(arrayPtr, size, index + 1, 0);
    } else if (arrayPtr[index] > arrayPtr[maxIndex]) {
        return findMaxIndexR(arrayPtr, size, index + 1, index);
    } else {
        return findMaxIndexR(arrayPtr, size, index + 1, maxIndex);
    }
}

int findMaxIndex(const int *const arrayPtr, const int size) {
    return findMaxIndexR(arrayPtr, size, 0, -1);
}


int findR(const int *const arrayPtr, const int size, const int numToFind, int index) {
    if (index > (size-1)) {
        return -1;
    } else if (arrayPtr[index] == numToFind) {
        return index;
    } else if (arrayPtr[index] != numToFind) {
        return findR(arrayPtr, size, numToFind, index+1);
    } else {
        return -1;
    }
}


int find(const int *const arrayPtr, const int size, const int numToFind) {
    return findR(arrayPtr, size, numToFind, 0);
}

int findLastR(const int *const arrayPtr, const int size, const int numToFind, int index) {
    if (index < 0) {
        return -1;
    } else if (arrayPtr[index] == numToFind) {
        return index;
    } else {
        return findLastR(arrayPtr, size, numToFind, index-1);
    }
}

int findLast(const int *const arrayPtr, const int size, const int numToFind) {
    return findLastR(arrayPtr, size, numToFind, size-1);
}

int binFindR(const int *const arrayPtr, const int size, const int numToFind, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = (left+right)/2;
    if (arrayPtr[mid] == numToFind) {
        return mid;
    } else if (numToFind < arrayPtr[mid]) {
        return binFindR(arrayPtr, size, numToFind, left, mid-1);
    } else {
        return binFindR(arrayPtr, size, numToFind, mid+1, right);
    }
}

int binFind(const int *const arrayPtr, const int size, const int numToFind) {
    return binFindR(arrayPtr, size, numToFind, 0, size-1);
}

int genRandInt(int min, int max, int *numLinesRun) {
    (*numLinesRun)+=5;
    if (min > max) {
        std::cout << "Min constraint cannot exceed maximum." << std::endl;
        return -1;
    }
    int range = max - min + 1;
    return random() % range + min;
}


int *genRandArray(int size, int min, int max, int *numLinesRun) {
    //Swap if min > max
    (*numLinesRun)+=4;
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
        (*numLinesRun)+=3;
    }
    int* randomArray = new int[size];
    (*numLinesRun)+=2;
    for (int i = 0; i < size; i++) {
        randomArray[i] = genRandInt(min, max, numLinesRun);
        (*numLinesRun)+=3;
    }
    (*numLinesRun)++;
    return randomArray;
}


int *genShuffledArray(int size, int *numLinesRun) {
    (*numLinesRun)+=2;
    if (size < 1) {
        (*numLinesRun)++;
        return nullptr;
    }
    int* shuffledArray = new int[size];
    (*numLinesRun)+=2;
    for (int i = 0; i < size; i++) {
        shuffledArray[i] = getShuffledNumber(shuffledArray, size, i, numLinesRun);
        (*numLinesRun)+=3;
    }
    (*numLinesRun)++;
    return shuffledArray;
}

void sort(int *arrayToSort, int size, int *numLinesRun) {
    (*numLinesRun)+=4;
    for (int i = 0; i < size; i++) {
        (*numLinesRun)+=2;
        for (int j = i+1; j < size; j++) {
            (*numLinesRun)+=3;
            if (arrayToSort[i] > arrayToSort[j]) {
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[j];
                arrayToSort[j] = temp;
                (*numLinesRun)+=3;
            }
        }
    }
}

int* copyArray(const int *arrayToCopy, int size, int *numLinesRun) {
    (*numLinesRun)+=4;
    int* copyArray = new int[size];
    for (int i = 0; i < size; i++) {
        copyArray[i] = arrayToCopy[i];
        (*numLinesRun)+=2;
    }
    return copyArray;
}

