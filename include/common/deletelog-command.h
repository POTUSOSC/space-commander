/*=============================================================================
*
*   AUTHOR      : Space Concordia 2014  -  Joseph
*
*   PURPOSE     : The DeleteLogCommand deletes the specified file  located in
*                 CS1_LOGS or CS1_TGZ directory.
*                 N.B.  We should NEVER have to delete files in the CS1_LOGS
*                       folder, only in the CS1_TGZ folder, but we keep the 
*                       functionnality just in case.
*
*============================================================================*/
#ifndef DELETELOG_COMMAND_H
#define DELETELOG_COMMAND_H

#include <sys/types.h>
#include "icommand.h"
#include "infobytes.h"

#define LOG 0x0
#define TGZ 0x1

using namespace std;

class InfoBytesDeleteLog : public InfoBytes
{
    public:
    char delete_status;
    const char* filename;

    string* ToString() {
        string* infoStatus = new string (1, delete_status);
        return infoStatus;
    }
};

class DeleteLogCommand : public ICommand 
{
    private :

        char filename[CS1_PATH_MAX];
        char type;

    public :

        DeleteLogCommand(const char* filename);
        DeleteLogCommand(ino_t inode);
        virtual ~DeleteLogCommand();
        virtual void* Execute(size_t* size);
        char FindType();
        void SaveFilename(ino_t inode);
        char* ExtractFilenameFromFile();
        InfoBytes* ParseResult(char *result);
};

#endif
