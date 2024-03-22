#ifndef CLIENT_H
#define CLIENT_H

#include "Channel.h"
#include "ViewTube.h"

class Client{

    // member variables
    private:
        string name;
        Channel* channel;

    public:
        // constructor
        Client(const string& newName);

        // destructor
        ~Client();

        // other methods
        bool download(const ViewTube& viewTube, int index);
        void print() const;
        void printChannel() const;
        void play(int index) const;
};

#endif