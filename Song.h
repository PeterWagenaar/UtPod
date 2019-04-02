//
// Created by peter on 3/27/2019.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>

using namespace std;

class Song {

private:
    string title;           //song title
    string artist;          //song artist
    int size;               //song size
public:

    Song();                 //default constructor
                            //sets a a songs size to 0, the artist and title to blank

    //Constructor with parameters
    //The user of the class will pass these.
    Song(string const &artist, string const &title, int size);

    /* FUNCTION - void setTitle
     * sets the title of the song
    */
    void setTitle(string const &title);
    /* FUNCTION - void setArtist
     * sets the artist of the song
    */
    void setArtist(string const &artist);
    /* FUNCTION - void setSize
     * sets the size of the song
    */
    void setSize(int size);
    /* FUNCTION - string getTitle
     * gets the title of the song
    */
    string getTitle() const;
    /* FUNCTION - string getArtist
     * gets the artist of the song
    */
    string getArtist() const;
    /* FUNCTION - int getSize
     * gets the size of the song
    */
    int getSize() const;

    /* FUNCTION - bool operator==
     * overloads the operator == for Songs
     * checks whether or not the songs are the same
    */
    bool operator==(const Song &s);
    /* FUNCTION - bool operator>
     * overloads the operator for > for Songs
     * checks whether or not one song is greater than the other
    */
    bool operator>(const Song &s);

};

#endif //UTPOD_SONG_H
