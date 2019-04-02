//
// Created by peter on 3/27/2019.
//

#include "Song.h"
#include "iostream"
#include <string>

using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
}

Song::Song(string const &_artist, string const &_title, int _size){
    artist = _artist;
    title = _title;
    size = _size;
}

void Song::setTitle(string const &title){
    this->title= title;
}

string Song::getTitle() const{
    return title;
}

void Song::setArtist(string const &artist){
    this->artist = artist;
}

string Song::getArtist() const{
    return artist;
}

void Song::setSize(int size){
    this->size = size;
}

int Song::getSize() const{
    return size;
}


bool Song::operator==(const Song &s) {

    return ((this->getSize() == s.getSize()) && (this->getTitle() == s.getTitle()) &&
            (this->getArtist() == s.getArtist()));
}

bool Song::operator>(const Song &s){
    if(this->getTitle() > s.getTitle()){
        return true;
    }
    if(this->getTitle() == s.getTitle()){
        if(this->getArtist() > s.getArtist()){
            return true;
        }
        if(this->getArtist() == s.getArtist()){
            if(this->getSize() > s.getSize()){
                return true;
            }
            if(this->getSize() == s.getSize()){
                return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
