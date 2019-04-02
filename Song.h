//
// Created by peter on 3/27/2019.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>

using namespace std;

class Song {

private:
    string title;
    string artist;
    int size;
public:
    Song();
    Song(string const &artist, string const &title, int size);

    void setTitle(string const &title);
    void setArtist(string const &artist);
    void setSize(int size);
    string getTitle() const;
    string getArtist() const;
    int getSize() const;

    bool operator==(const Song &s);
    bool operator>(const Song &s);

};

#endif //UTPOD_SONG_H
