#include "FrequencyCounter.h"
#include "Huffman.h"

int main()
{
    FrequencyCounter frequencyCounter ;
    Huffman huffman;
    frequencyCounter.readFile("../input.txt");
    huffman.huffer(frequencyCounter.getFrequencyMap());
    huffman.compressTofile("../output.txt");
    return 0;
}