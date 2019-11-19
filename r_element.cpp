#include "r_element.h"

#include "neurontrainer.h"

R_Element::R_Element(SingleNeuron** trainedArray) :
    trainedSingleNeuronArray(trainedArray)
{

}

unsigned R_Element::getResult(unsigned char* array)
{
    for(int i = 0; i < ::neuronAmount; i++)
    {
        trainedSingleNeuronArray[i]->setInput(array);
        if(trainedSingleNeuronArray[i]->getResult()) return i;
    }
}
