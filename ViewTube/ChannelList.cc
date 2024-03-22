#include "ChannelList.h"

// constructor
ChannelList::ChannelList(){
	numChannels = 0;
	channels = new Channel*[MAX_CHANNELS];
}

// destructor
ChannelList::~ChannelList(){
	for(int i=0; i<numChannels; i++){
		if(channels[i]){
			delete channels[i];
		}
	}

	delete [] channels;
}

// method to add the channel
bool ChannelList::addChannel(Channel* c){
	if (numChannels >= MAX_CHANNELS) return false;
	channels[numChannels] = c;
	++numChannels;
	return true;
}

// This is not an ideal implementation.
// If more than one video has the same title it will remove
// the last one only.
Channel* ChannelList::removeChannel(const string& title){
	Channel* goner = nullptr;
	bool found = false;
	for (int i = 0; i < numChannels; ++i){
		if (title == channels[i]->getTitle()){
			goner = channels[i];
			found = true;
		}
		if (found && i < numChannels-1){
			channels[i]=channels[i+1];
		}
	}
	if (found) --numChannels; 
	return goner;
}

// method to remove the channel
Channel* ChannelList::removeChannel(int index){
	if (index < 0 || index >= numChannels) return nullptr;
	Channel* goner = channels[index];
	for (int i = index; i < numChannels-1; ++i){
		channels[i] = channels[i+1];
	}
	--numChannels;
	return goner;
}

// method to get the channel by title
Channel* ChannelList::getChannel(const string& title) const {
	for (int i = 0; i < numChannels; ++i){
		if (title == channels[i]->getTitle()){
			return channels[i];
		}
	}
	return nullptr;
}

// method to get the channel by index
Channel* ChannelList::getChannel(int index) const{
	if (index < 0 || index >= numChannels) return nullptr;
	return channels[index];
}

// method to return the size of the channel list
int ChannelList::size() const{
	return numChannels;
}

// method to print out all the channels in the channel list
void ChannelList::print() const{
	for (int i = 0; i < numChannels; ++i){
        std::cout << i << ") ";
		channels[i]->print();
		std::cout << std::endl;
	}
}

// method to check if the channel list is full
bool ChannelList::isFull() const{
    if(MAX_CHANNELS <= numChannels){
        return true;
    }
    else{
        return false;
    }
}

// method to get the num of channels in the channel list
int ChannelList::getNumOfChannels() const{
    return numChannels;
}
