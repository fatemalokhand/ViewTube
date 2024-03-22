#include "Channel.h"

// constructor
Channel::Channel(const string& title, const string& owner){
    cTitle = title;
    cOwner = owner;
    cVideoList = new VideoList();
}

// copy constructor
Channel::Channel(const Channel& chan){
    cTitle = chan.cTitle;
    cOwner = chan.cOwner;
    cVideoList = new VideoList();
    Video* v;
    for(int i=0; i<chan.cVideoList->size(); i++){
        v = chan.cVideoList->getVideo(i);
        cVideoList->addVideo(new Video(*v));
    }
}

// destructor
Channel::~Channel(){
    delete cVideoList;
}

// get method for title
string Channel::getTitle() const{
    return cTitle;
}

// get method for owner
string Channel::getOwner() const{
    return cOwner;
}

// checks if this Channel's title comes before the parameter's title in alphabetical order
bool Channel::lessThan(const Channel& channel) const{
    if(this->cTitle < channel.cTitle){
        return true;
    }
    else{
        return false;
    }
}

// method to add video to the channel
bool Channel::addVideo(const string& title, const string& content, const Date& date){
    Video* newVideo = new Video(title, content, date);
    bool value = cVideoList->addVideo(newVideo);
    if(value == true){
        std::cout << "Video was added successfully." << std::endl;
        return true;
    }
    else{
        std::cout << "Video was not added." << std::endl;
        delete newVideo;
        return false;
    }
}

// method to remove video from the channel
bool Channel::removeVideo(int index){
    Video* video = cVideoList->removeVideo(index);
    if(video == nullptr){
        // index is invalid
        std::cout << "Cannot remove the video because the video does not exist." << std::endl;
        return false;
    }
    else{
        delete video;
        std::cout << "Video was removed successfully." << std::endl;
        return true;
    }
}

// returns the num of videos
int Channel::getNumVideos() const{
    return cVideoList->size();
}

// printing out the channel's title and owner
void Channel::print() const{
    std::cout << "Channel title: " << cTitle << std::endl;
    std::cout << "Channel owner: " << cOwner << std::endl;
}

// prints out the metadata for the Channel and also prints all the Videos
void Channel::printVideos() const{
    this->print();
    cVideoList->print();
}

// method to play the Video at the given index
void Channel::playVideo(int index) const{
    Video* video = cVideoList->getVideo(index);
    if(video == nullptr){
        std::cout << "Index is invalid." << std::endl;
    }
    else{
        video->play();
    }
}
