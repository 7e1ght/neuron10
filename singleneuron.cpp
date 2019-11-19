#include "singleneuron.h"

#include <fstream>
#include <unistd.h>
#include <iostream>

using namespace std;

void SingleNeuron::writeCoefs()
{
    ofstream out(prefix+to_string(target), ios::binary);

    out.write((char*) &coefs, sizeof (coefs));

    out.close();
}

void SingleNeuron::training()
{
    srand(time(0));
    int num;
    int correctAnswers = 0;
    while(!trained)
    {
        num = rand() % 10;

        setInput(::numbers[num]);

        if(getResult())
        {
            if(num != target)
            {
                trainMinusOne();
                correctAnswers = 0;
            }
            else correctAnswers++;
        }
        else
        {
            if(num == target)
            {
                trainPlusOne();
                correctAnswers = 0;
            }
            else correctAnswers++;
        }

        if(correctAnswers >= ::correctAnswersLimit)
            trained = true;

        counter++;
    }

}

void SingleNeuron::trainMinusOne()
{
    for(int i = 0; i < ::signalNum; i++)
        if(input[i] == 1) coefs[i] -= 1;

    writeCoefs();
}

void SingleNeuron::trainPlusOne()
{
    for(int i = 0; i < ::signalNum; i++)
        if(input[i] == 1) coefs[i] += 1;

    writeCoefs();
}

bool SingleNeuron::getResult()
{
    int res = 0;
    for(int i = 0; i < ::signalNum; i++)
        res += input[i]*coefs[i];

    return res >= 0;
}

bool SingleNeuron::isTrained()
{
    return trained;
}

void SingleNeuron::start()
{
    training();
}

unsigned int SingleNeuron::getCounter()
{
    return counter;
}

void SingleNeuron::setInput(const unsigned char* inputArray)
{
    for(int i = 0; i < ::signalNum; i++)
    {
        input[i] = inputArray[i];
    }
}

SingleNeuron::SingleNeuron(int learnNum) : target(learnNum)
{
    trained = false;
    counter = 0;
    ifstream in(prefix + to_string(target), ios::binary);

    if(in.is_open())
    {
        in.read((char*)&coefs, sizeof (coefs));
        trained = true;
    }
    else
        for(int i = 0; i < ::signalNum; i++)
            coefs[i] = 0;

    in.close();
}
