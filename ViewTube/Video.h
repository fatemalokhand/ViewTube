#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include "Date.h"

class Video{

    // member variables
    private:
        string vTitle;
        string vContent;
        Date dateUploaded;

    public:
        // constructor
        Video(const string& title, const string& content, const Date& date);
        Video();

        // other methods
        string getTitle() const;
        bool lessThan(const Video& video) const;
        void print() const;
        void play() const;
};

#endif