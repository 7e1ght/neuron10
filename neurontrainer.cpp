#include "neurontrainer.h"

#include <thread>
#include <unistd.h>
#include <iostream>

using namespace std;

thread threads[::neuronAmount];

NeuronTrainer::NeuronTrainer(SingleNeuron** singleNeuronArray) :
    trainTarget(singleNeuronArray)
{
}

int NeuronTrainer::countOne()
{
    unsigned counter = 0;
    for(unsigned i = 0; i < ::neuronAmount; i++)
        if(trainTarget[i]->isTrained() == true)
            counter++;

    return counter;
}

void NeuronTrainer::check()
{
    unsigned neuronsReady = countOne();

    while(neuronsReady != ::neuronAmount)
    {
        sleep(1);
        neuronsReady = countOne();
    }

    if(neuronsReady == ::neuronAmount)
        for(unsigned i = 0; i < ::neuronAmount; i++)
            cout << "neuron" << i << " trained in " << trainTarget[i]->getCounter() << " steps" << endl;
}

void NeuronTrainer::startTrain()
{
    for(int i = 0; i < ::neuronAmount; i++)
    {
        trainTarget[i] = new SingleNeuron(i);
    }

    for(int i = 0; i < ::neuronAmount; i++)
        threads[i] = thread(&SingleNeuron::start, trainTarget[i]);

    check();

    for(int i = 0; i < ::neuronAmount; i++)
        threads[i].join();

    for(int i = 0; i < ::neuronAmount; i++)
        delete trainTarget[i];
}
