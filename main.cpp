#include "FrequencyCounter.h"
#include "Huffman.h"

std::ifstream::pos_type filesize(const char* filename);

int main()
{
    FrequencyCounter frequencyCounter ;
    Huffman huffman;
    string workingMode;
    cin >> workingMode;
    if(workingMode == "compress")
    {
        clock_t tStart = clock();
        frequencyCounter.readFile("../input.txt");
        huffman.huffer(frequencyCounter.getFrequencyMap());
        huffman.compressTofile("../input.txt","../output.txt");
        cout <<"Time taken: "<<(1.0*(clock() - tStart)/CLOCKS_PER_SEC)<<"sec"<<endl;
        cout << "Input File Size : "<<filesize("../input.txt")<<" bytes."<<endl;
        cout<< "Compressed File Size : "<<filesize("../output.txt")<<" bytes."<<endl;
        cout<< "Compression Ratio : "<<(1.0*filesize("../output.txt")/filesize("../input.txt"))<<endl;
    }
    else if(workingMode == "decompress")
    {
        clock_t tStart = clock();
        huffman.deHuffer("../output.txt","../output2.txt");
        cout <<"Time taken: "<<(1.0*(clock() - tStart)/CLOCKS_PER_SEC)<<"sec"<<endl;
        cout << "Input File (Compressed) Size : "<<filesize("../output.txt")<<" bytes."<<endl;
        cout<< "DeCompressed File Size : "<<filesize("../output2.txt")<<" bytes."<<endl;
    }


    return 0;
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}