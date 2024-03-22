#ifndef CHANNEL_H
#define CHANNEL_H

#include "VideoList.h"

class Channel{

    // member variables
    private:
        string cTitle;
        string cOwner;
        VideoList* cVideoList; 

    public:
        // constructor
        Channel(const string& title, const string& owner);

        // copy constructor
        Channel(const Channel& c);

        // destructor
        ~Channel();

        // get methods
        string getTitle() const;
        string getOwner() const;
        int getNumVideos() const;
        
        // other methods
        bool lessThan(const Channel& channel) const;
        bool addVideo(const string& title, const string& content, const Date& date);
        bool removeVideo(int index);
        void print() const;
        void printVideos() const;
        void playVideo(int index) const;
};

#endif