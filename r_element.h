#ifndef R_ELEMENT_H
#define R_ELEMENT_H

#include "singleneuron.h"

/*
 *  Класс для определение числа
 */

class R_Element
{
private:
    SingleNeuron** trainedSingleNeuronArray;
public:
    R_Element(SingleNeuron** trainedArray);
    unsigned getResult(int*);
};

#endif // R_ELEMENT_H
