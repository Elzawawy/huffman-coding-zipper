#include "FrequencyCounter.h"
#include "Huffman.h"

int main()
{
    FrequencyCounter frequencyCounter ;
    Huffman huffman;
    string workingMode;
    cin >> workingMode;
    if(workingMode == "compress")
    {
        frequencyCounter.readFile("../input.txt");
        huffman.huffer(frequencyCounter.getFrequencyMap());
        huffman.compressTofile("../input.txt","../output.txt");
    }
    else if(workingMode == "decompress")
        huffman.deHuffer("../output.txt","../output2.txt");

    return 0;
}