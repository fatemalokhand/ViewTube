#include "Client.h"

// constructor
Client::Client(const string& newName){
    name = newName;
    channel = nullptr;
}

// destructor
Client::~Client(){
    delete channel;
}

// download function
bool Client::download(const ViewTube& viewTube, int index){
    if(channel != nullptr){
        delete channel;
        channel = nullptr;
    }
    
    bool value = viewTube.download(index, &channel);

    if(value == true){
        // making a deep copy of this Channel
        channel = new Channel(*channel);
        return true;
    }
    else{
        std::cout << "Channel did not get downloaded." << std::endl;
        channel = nullptr;
        return false;
    }
}

// Printing out the Client name and the Channel
void Client::print() const{
    std::cout << "Client's name: " << name << std::endl;
    if(channel == nullptr){
        std::cout << "Cannot print." << std::endl;
    }
    else{
        channel->print();
    }
}

// printing out the Channel along with the Videos
void Client::printChannel() const{
    if(channel == nullptr){
        std::cout << "Cannot print the channel." << std::endl;
    }
    else{
        channel->printVideos();
    }
}

// playing the Video stored at the given index
void Client::play(int index) const{
    if(channel == nullptr){
        std::cout << "Cannot play the video." << std::endl;
    }
    else{
        channel->playVideo(index);
    }
}