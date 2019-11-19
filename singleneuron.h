#ifndef SINGLENEURON_H
#define SINGLENEURON_H

#include <string>

namespace
{
    const int signalNum = 15;
    const std::string prefix = "coefs";
    const int correctAnswersLimit = 500;

    const unsigned char numbers[10][15] =
    {
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},  // 0
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},  // 1
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},  // 2
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},  // 3
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},  // 4
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},  // 5
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},  // 6
        {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},  // 7
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},  // 8
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}   // 9
    };
}

class SingleNeuron
{
private:
    int target;
    bool trained;
    int coefs[::signalNum];
    int input[::signalNum];
    unsigned int counter;

    void writeCoefs();
    void training();
    void trainMinusOne();
    void trainPlusOne();
    bool getResult();
public:
    bool isTrained();
    void start();
    unsigned int getCounter();
    void setInput(const unsigned char* inputArray);

    SingleNeuron(int learnNum);
};

#endif // SINGLENEURON_H
