//
// Created by Mark Volkov on 10/10/17.
//

#include "ArrayList.h"
#include "ArrayLib.h"

ArrayList::ArrayList(int initialCapacity) {
    currCapacity = initialCapacity;
    currItemCount = 0;
    array = new int[currCapacity];
}

ArrayList::ArrayList(const ArrayList &arrayListToCopy) {
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    array = new int[currCapacity];
    if (currItemCount > 0) {
        for (int i = 0; i <= currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
    }
}

ArrayList::~ArrayList() {
    delete[] array;
    array = nullptr;
}

ArrayList &ArrayList::operator=(const ArrayList &arrayListToCopy) {
    delete[] array;
    array = nullptr;
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    array = new int[currCapacity];
    if (currItemCount > 0) {
        for (int i = 0; i <= currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
    }

}

//Is this memory management correct?
void ArrayList::doubleCapacity() {
    int* newArray = new int[currCapacity*2];
    for (int i = 0; i < currCapacity; i++) {
        newArray[i] = array[i];
    }
    currCapacity*=2;
    delete[] array;
    array = newArray;
    newArray = nullptr;
}

void ArrayList::insertAtEnd(int itemToAdd) {
    if (currItemCount >= currCapacity) {
        doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount++;
}

void ArrayList::insertAtFront(int itemToAdd) {
    insertAt(itemToAdd, 0);
}

void ArrayList::insertAt(int itemToAdd, int index) {
    if (index >= currItemCount && currItemCount != 0) {
        throw std::out_of_range("Index out of range.");
    }
    if (currItemCount >= currCapacity) {
        doubleCapacity();
    }
    currItemCount++;
    int temp = array[index];
    for (int i = index; i < currItemCount; i++) {
        if (i == index) {
            array[index] = itemToAdd;
        } else {
            int next = array[i];
            array[i] = temp;
            temp = next;
        }
    }
}

int ArrayList::getValueAt(int index) {
    if (index < currItemCount && index >= 0) {
        return array[index];
    } else {
        throw std::out_of_range("Index out of range.");
    }
}

int ArrayList::removeValueAt(int index) {
    if (index > currItemCount-1  || index < 0) {
        throw std::out_of_range("Index out of range.");
    }
    int copyVal = array[index];
    for (int i = index; i < currItemCount; i++) {
        for (int j = i+1; j < currItemCount;) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            break;
        }
    }
    currItemCount--;
    return copyVal;
}

bool ArrayList::isEmpty() {
    return currItemCount==0;
}

int ArrayList::itemCount() {
    return currItemCount;
}

void ArrayList::clearList() {
    delete[] array;
    array = new int[currCapacity];
    currItemCount = 0;
}

std::string ArrayList::toString() {
    return COMP220LAB_ARRAYLIB_H::toString(array, currItemCount);
}

int ArrayList::findMaxIndex() {
    if (currItemCount < 1) {
        throw std::out_of_range("ArrayList is empty.");
    }
    return COMP220LAB_ARRAYLIB_H::findMaxIndex(array, currItemCount);
}

int ArrayList::find(int numToFind) {
    if (currItemCount < 1) {
        return -1;
    }
    return COMP220LAB_ARRAYLIB_H::find(array, currItemCount, numToFind);
}

int ArrayList::findLast(int numToFind) {
    if (currItemCount < 1) {
        return -1;
    }
    return COMP220LAB_ARRAYLIB_H::findLast(array, currItemCount, numToFind);
}
