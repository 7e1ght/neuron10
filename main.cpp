#include <iostream>
#include <thread>
#include <unistd.h>

#include "singleneuron.h"
#include "neurontrainer.h"
#include "r_element.h"

using namespace std;

int main()
{
    SingleNeuron* neurons[::neuronAmount];

    for(int i = 0; i < ::neuronAmount; i++)
        neurons[i] = new SingleNeuron(i);

//    NeuronTrainer trainer(neurons);
//    trainer.startTrain();

    R_Element re(neurons);
    cout << re.getResult(::numbers[2]) << endl;

    return 0;
}
