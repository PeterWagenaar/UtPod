//
// Created by peter on 3/27/2019.
//

#include "UtPod.h"
#include "iostream"
#include <chrono>

UtPod::UtPod(){

    songs = nullptr;
    this->podMemSize = MAX_MEMORY;

}

UtPod::UtPod(int size){

    songs= nullptr;
    if(size>0 && size<=512) {
        this->podMemSize = size;
    }
    else this->podMemSize = MAX_MEMORY;

}

int UtPod::addSong(Song const &s) {

    if((getRemainingMemory()<s.getSize())){
        return NO_MEMORY;
    }
    else {
        auto *song = new SongNode();

        song->s.setSize(s.getSize());
        song->s.setTitle(s.getTitle());
        song->s.setArtist(s.getArtist());

        song->next = songs;
        songs = song;

        return SUCCESS;
    }

}

int UtPod::removeSong(Song const &s) {

    UtPod::SongNode *temp;
    UtPod::SongNode *temp2;
    temp = songs;
    temp2 = songs;

    if(temp->s==s){

        songs = temp->next;

        delete temp;

        return UtPod::SUCCESS;

    }

    while(temp!=nullptr){

        if(temp->s==s){

            temp2->next = temp->next;

            delete temp;

            return UtPod::SUCCESS;

        }
        temp2=temp;
        temp = temp->next;

    }
    return UtPod::NOT_FOUND;

}

void UtPod::shuffle() {

    UtPod::SongNode *temp;
    UtPod::SongNode *temp2;
    srand((unsigned)time(nullptr));

    int random = 0;

    int size = 0;

    size = numSongs();

    for(int num= size; num>0 ;num--) {
        random = rand() % (size) + 1;

        temp = songs;
        temp2= songs;

        for(int i = 0; i<random; i++){

            temp = temp2;
            temp2 = temp2->next;

        }

        temp->next = songs;
        temp= songs->next;
        songs->next = temp2;

        songs = temp;
    }



}

void UtPod::showSongList() {

    UtPod::SongNode *temp;
    int counter = 1;

    temp = songs;

    while(temp!= nullptr) {
        cout<<"Song " << counter << ": " << temp->s.getArtist() << ", " << temp->s.getTitle() << ", " << temp->s.getSize() << endl;
        counter++;
        temp = temp->next;
    }
}

void UtPod::sortSongList() {

    UtPod::SongNode *temp;
    UtPod::SongNode *temp2;
    UtPod::SongNode *temp3;

    temp = songs;
    temp3 = songs;

    while(temp->next!=nullptr){

        if(temp==songs && temp->next->s > temp->s){

            temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=temp;
            songs=temp2;
            temp = songs;

        }
        else if(temp->next->s > temp->s){

            temp2=temp->next;
            temp->next=temp2->next;
            temp2->next=temp;
            temp3->next=temp2;
            temp = songs;

        }
        else{
            temp3=temp;
            temp = temp->next;
        }

    }

}

void UtPod::clearMemory() {

    UtPod::SongNode *temp;
    UtPod::SongNode *temp2;
    temp = songs;

    while(temp!=nullptr){

        temp2=temp;
        temp = temp->next;

        delete temp2;

    }

    songs = nullptr;

}

int UtPod::getRemainingMemory() {


    UtPod::SongNode *temp;
    int total = 0;

    temp = songs;

    while(temp!=nullptr){

        total+= temp->s.getSize();
        temp = temp->next;

    }

    return getTotalMemory() - total;

}

int UtPod::numSongs() {

    UtPod::SongNode *temp;

    temp = songs;

    int size = 0;

    while(temp!= nullptr) {
        size++;

        temp = temp->next;
    }

    return size;
}


UtPod::~UtPod(){

    clearMemory();

}
