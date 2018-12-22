#include "FrequencyCounter.h"
#include "Huffman.h"

int main()
{
    FrequencyCounter frequencyCounter ;
    Huffman huffman;
    frequencyCounter.readFile("../input.txt");
    huffman.huffer(frequencyCounter.getFrequencyMap());
    huffman.compressTofile("../output.txt");
    huffman.deHuffer("../output.txt");
    char a = -58;
    bitset<8> x(a);
    cout << x;

    return 0;
}