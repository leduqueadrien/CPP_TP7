
#ifndef PILEGEN_IMP_HPP
#define PILEGEN_IMP_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>


template<typename T>
PileGen <T>::PileGen(int size) : taille(size), nbElem(0), tab(nullptr) {
    if (taille > 0) {
        try {
            tab = new T [taille];
        } catch (std::bad_alloc & e) {
            std::cout << e.what() << std::endl;
            taille = -1;
        }
    } else {
        throw std::invalid_argument("");
    }
}

template<typename T>
PileGen <T>::~PileGen() {
    delete [] tab;
}

template<typename T>
int PileGen<T>::size() {
    return nbElem;
}

template<typename T>
bool PileGen<T>::empty() {
    return nbElem < 1;
}

template<typename T>
void PileGen<T>::push(T const & valeur) {
    if (nbElem >= taille) {
        try {
            double * newTab = new double [taille*2];
            memcpy(newTab, tab, taille);
            taille *= 2;
            delete [] tab;
            tab = newTab;
        } catch (std::bad_alloc & e) {
            std::cout << e.what() << std::endl;
        }
    }
    *(tab + nbElem) = valeur;
    nbElem ++;
}

template<typename T>
T & PileGen<T>::pop () {
    if (empty()) {
        throw std::invalid_argument("");
    }
    nbElem--;
    return *(tab + nbElem);
}

template<typename T>
T & PileGen<T>::top() {
    if (empty()) {
        throw std::invalid_argument("");
    }
    return *(tab + nbElem - 1);
}

#endif 