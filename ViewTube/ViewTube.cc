#include "ViewTube.h"

// constructor
ViewTube::ViewTube(){
    channelList = new ChannelList();
}

// destructor
ViewTube::~ViewTube(){
    delete channelList;
}

// Using the arguments to make a new Channel and add it to the ChannelList
void ViewTube::addChannel(const string& title, const string& owner){
    Channel* newChannel = new Channel(title, owner);

    bool value = channelList->addChannel(newChannel);
    if(value == true){
        std::cout << "Channel was added successfully." << std::endl;
    }
    else{
        // channel list does not have space
        std::cout << "Cannot add the channel." << std::endl;
        delete newChannel;
    }
}

// removing and deleting the Channel at the given index from the ChannelList
void ViewTube::deleteChannel(int index){
    Channel* channelToRemove = channelList->removeChannel(index);
    if(channelToRemove == nullptr){
        // index is invalid so the channel does not exist
        std::cout << "Channel cannot be deleted because the channel does not exist." << std::endl;
    }
    else{
        std::cout << "Channel was deleted successfully." << std::endl;
        delete channelToRemove;
    }
}

// returning the number of Channels being stored in ViewTube
int ViewTube::getNumChannels() const{
    return channelList->getNumOfChannels();
}

// download function
bool ViewTube::download(int index, Channel** channel) const{
    Channel* channelAtIndex = channelList->getChannel(index);
    if(channelAtIndex == nullptr){
        return false;
    }
    else{
        *channel = channelAtIndex;
        return true;
    }
}

// If the Channel exists and there is room in the Channel, creating a new video and adding it to the Channel
void ViewTube::addVideo(const string& channel, const string& title, const string& content, const Date& date){
    Channel* theChannel = channelList->getChannel(channel);
    if(theChannel == nullptr){
        // channel does not exist and cannot add video to the channel
        std::cout << "Cannot add video because the channel does not exist." << std::endl;
        return;
    }

    bool value = theChannel->addVideo(title, content, date);
    if(value == true){
        std::cout << "Video was added successfully." << std::endl;
    }
    else{
        std::cout << "Video was not added." << std::endl;
    }
}

// removing and deleting the Video at the given index from the Channel
void ViewTube::deleteVideo(int channel, int video){
    Channel* theChannel = channelList->getChannel(channel);

    if(theChannel == nullptr){
        // channel does not exist
        std::cout << "Cannot delete the video because the channel does not exist." << std::endl;
        return;
    }
    
    bool value = theChannel->removeVideo(video);
    if(value == true){
        std::cout << "Video was deleted successfully." << std::endl;
    }
    else{
        std::cout << "Video was not deleted." << std::endl;
    }
}

// printing out all the Channels stored in ViewTube
void ViewTube::printChannels() const{
    std::cout << std::endl;
    std::cout << "ViewTube" << std::endl;
    std::cout << "========" << std::endl;
    std::cout << std::endl;
    channelList->print();
}

// printing out the Channel at the given index, if it exists
void ViewTube::printChannel(int index) const{
    Channel* channel = channelList->getChannel(index);
    if(channel == nullptr){
        std::cout << "The channel does not exist." << std::endl;
    }
    else{
        channel->printVideos();
    }
}

// If there is a Channel at the given channel index, with a Video at the given video index, playing the Video
void ViewTube::playVideo(int channelIndex, int videoIndex) const{
    Channel* channel = channelList->getChannel(channelIndex);

    if(channel == nullptr){
        std::cout << "Channel does not exist." << std::endl;
    }
    else{
        channel->playVideo(videoIndex);
    }
}