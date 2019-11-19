#ifndef NEURONTRAINER_H
#define NEURONTRAINER_H

#include "singleneuron.h"

namespace
{
    const int neuronAmount = 10;
}

class NeuronTrainer
{
private:
    SingleNeuron** trainTarget;

    void check();
    int countOne();
public:
    void startTrain();
    NeuronTrainer(SingleNeuron** singleNeuronArray);
};

#endif // NEURONTRAINER_H
