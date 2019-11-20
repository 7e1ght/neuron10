#include "r_element.h"

#include "neurontrainer.h"
#include <iostream>

using namespace std;

R_Element::R_Element(SingleNeuron** trainedArray) :
    trainedSingleNeuronArray(trainedArray)
{

}

unsigned R_Element::getResult(int* array)
{
    for(int i = 0; i < ::neuronAmount; i++)
    {
        trainedSingleNeuronArray[i]->setInput(array);
        if(trainedSingleNeuronArray[i]->getResult()) return i;
    }
}
