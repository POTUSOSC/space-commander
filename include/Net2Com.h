#ifndef _NET2COM_H_
#define _NET2COM_H_
#include <NamedPipe.h>

enum PIPE_NUM{
    PIPE_ONE, PIPE_TWO, PIPE_THREE, PIPE_FOUR
};

class Net2Com{
    private :
        static const int NUMBER_OF_PIPES = 4;
        static const char* pipe_str[];
         
        NamedPipe* pipe[NUMBER_OF_PIPES];
        
        NamedPipe* dataPipe_w;
        NamedPipe* dataPipe_r;
        NamedPipe* infoPipe_w;
        NamedPipe* infoPipe_r;

    public :
        Net2Com(PIPE_NUM dataw, PIPE_NUM datar, PIPE_NUM infow, PIPE_NUM infor);        // DATA_WRITE, DATA_READ, INFO_WRITE, INFO_READ
        ~Net2Com();
        int WriteToDataPipe(const char* str);
        int WriteToDataPipe(unsigned char);
        char* ReadFromDataPipe(char* buffer);
        int WriteToInfoPipe(const char* str);
        int WriteToInfoPipe(unsigned char);
        char* ReadFromInfoPipe(char* buffer);

    private :
        bool Initialize();
        bool CreatePipes();
};
#endif