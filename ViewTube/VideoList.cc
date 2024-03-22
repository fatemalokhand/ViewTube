#include "VideoList.h"

// constructor
VideoList::VideoList(){
	numVideos = 0;
	videos = new Video*[MAX_VIDS];
}

// destructor
VideoList::~VideoList(){
	for(int i=0; i<numVideos; i++){
		if(videos[i]){
			delete videos[i];
		}
	}

	delete [] videos;
}

// method to add video
bool VideoList::addVideo(Video* p){
	if (numVideos >= MAX_VIDS) return false;
	for (int i = numVideos; i > 0; --i){
		if (p->lessThan(*videos[i-1])){
			videos[i] = videos[i-1];
		}else{
			videos[i] = p;
			++numVideos;
			return true;
		}
	}
	videos[0] = p;
	++numVideos;
	return true;
}

// This is not an ideal implementation.
// If more than one video has the same title it will remove
// the last one only.
Video* VideoList::removeVideo(const string& title){
	Video* goner = nullptr;
	bool found = false;
	for (int i = 0; i < numVideos; ++i){
		if (title == videos[i]->getTitle()){
			goner = videos[i];
			found = true;
		}
		if (found && i < numVideos-1){
			videos[i]=videos[i+1];
		}
	}
	if (found) --numVideos; 
	return goner;
}

// method to remove video
Video* VideoList::removeVideo(int index){
	if (index < 0 || index >= numVideos) return nullptr;
	Video* goner = videos[index];
	for (int i = index; i < numVideos-1; ++i){
		videos[i] = videos[i+1];
	}
	--numVideos;
	return goner;
}

// method to get video by title
Video* VideoList::getVideo(const string& title) const{
	for (int i = 0; i < numVideos; ++i){
		if (title == videos[i]->getTitle()){
			return videos[i];
		}
	}
	return nullptr;
}

// method to get video by index
Video* VideoList::getVideo(int index) const{
	if (index < 0 || index >= numVideos) return nullptr;
	return videos[index];
}

// method to get the size of the video list
int VideoList::size() const{
	return numVideos;
}

// method to print out the video list
void VideoList::print() const{
	for (int i = 0; i < numVideos; ++i){
		std::cout << i << ") ";
		videos[i]->print();
		std::cout << std::endl;
	}
}