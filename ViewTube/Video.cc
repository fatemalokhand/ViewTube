#include "Video.h"

// constructor
Video::Video(const string& title, const string& content, const Date& date){
    vTitle = title;
    vContent = content;
    dateUploaded = date;
}

// default constructor
Video::Video(){
    vTitle = "";
    vContent = "";
    dateUploaded = Date();
}

// get method for title
string Video::getTitle() const{
    return vTitle;
}

// checks if this Video’s Date comes before the parameter’s Date
bool Video::lessThan(const Video& video) const{
    if(this->dateUploaded.lessThan(video.dateUploaded)){
        return true;
    }
    else{
        return false;
    }
}

// prints out the video's title and date added
void Video::print() const{
    std::cout << "Video: " << vTitle << std::endl;
    std::cout << "Date added: ";
    dateUploaded.print();
    std::cout << std::endl;
}

// method to play the video
void Video::play() const{
    this->print();
    std::cout << "Content: " << vContent << std::endl;
}