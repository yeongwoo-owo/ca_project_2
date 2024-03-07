#include <iostream>
#include <fstream>
#include <cstdlib>
#include "code.h"
#include "cpu.h"

#define MAX_BUF 1000

using std::cout;
using std::endl;

bool isDataFileExist(int argc){
    if(argc==4){
        return true;
    }else{
        return false;
    }
}

int getBinaryInput(FILE* input, unsigned char* buf){
    fseek(input, 0, SEEK_END);
    int pos=ftell(input);
    fseek(input, 0, SEEK_SET);
    fread(buf, pos, 1, input);
    return pos;
}

int main(int argc, char** argv){
    int nInst=atoi(argv[1]);
    FILE* instFile=fopen(argv[2], "rb");
    FILE* dataFile;
    if(isDataFileExist(argc)){
        dataFile=fopen(argv[3], "rb");
    }
    
    unsigned char buf[MAX_BUF];
    int nInput=getBinaryInput(instFile, buf)/4;


    Code code(nInst);
    code.setCode(buf, nInput);
    // code.printCode();

    DataMemory memory;
    if(isDataFileExist(argc)){
        int nData=getBinaryInput(dataFile, buf);
        // printf("nData: %d\n", nData);
        memory.init(buf, nData);
        // memory.printMemory();
        // printf("\n");
    }

    CPU cpu;
    if(isDataFileExist(argc)){
        cpu.accessMemory(memory);
    }

    for(int i=0;i<nInst;i++){
        cpu.load(code);
        // cpu.printInst();
        cpu.run();
        // cpu.printRegisterValue();
        // if(isDataFileExist(argc)){
            // memory.printMemory();
            // printf("\n");
        // }
        // printf("\n");
    }
    cpu.printRegisterValue();

    fclose(instFile);
    if(isDataFileExist(argc)){
        fclose(dataFile);
    }

    return 0;
}
