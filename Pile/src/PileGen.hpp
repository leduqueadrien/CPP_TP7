
#ifndef PILEGEN_HPP
#define PILEGEN_HPP

template <typename T>
class PileGen {
    private :
        int taille;
        int nbElem;
        T * tab;
    
    public :
        PileGen(int = 10);
        ~PileGen();

        int size();

        bool empty();
        void push(T const &);
        T & pop();
        T & top();
        
};

#include "PileGen.impl.hpp"

#endif