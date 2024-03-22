#ifndef VIEWTUBE_H
#define VIEWTUBE_H

#include "ChannelList.h"

class ViewTube{

    // member variable
    private:
        ChannelList* channelList;

    public:
        // constructor
        ViewTube();

        // destructor
        ~ViewTube();

        // other methods
        void addChannel(const string& title, const string& owner);
        void deleteChannel(int index);
        int getNumChannels() const;
        bool download(int index, Channel** channel) const;
        void addVideo(const string& channel, const string& title, const string& content, const Date& date);
        void deleteVideo(int channel, int video);
        void printChannels() const;
        void printChannel(int index) const;
        void playVideo(int channelIndex, int videoIndex) const;
};

#endif