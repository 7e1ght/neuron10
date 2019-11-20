#include <iostream>
#include <thread>
#include <unistd.h>

#include "singleneuron.h"
#include "neurontrainer.h"
#include "r_element.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
//    unsigned char inputArray[::signalNum] = {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1};
    int inputArray[::signalNum] /*= {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}*/;
    SingleNeuron* neurons[::neuronAmount];

    for(int i = 0; i < ::neuronAmount; i++)
        neurons[i] = new SingleNeuron(i);

    R_Element re(neurons);

    for(int i = 1; i < argc; i++)
        inputArray[i-1] = *argv[i] - '0';

    cout << re.getResult(inputArray) << endl;

    return 0;
}
