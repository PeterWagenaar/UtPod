/* UtPodDriver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    UtPod p(256);

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    Song s8("Beatles", "Hey Jude8", 3);
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    t.addSong(s3);

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 3);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 6);
    result = t.addSong(s5);
    cout << "result = " << result << endl;

    Song s6("Beatles", "Hey Jude6", 5);
    result = t.addSong(s6);
    cout << "result = " << result << endl;

    Song s9("Beatles", "Hey Jude9", 300);
    result = t.addSong(s9);
    cout << "result = " << result << endl;

    t.showSongList();

    cout << "Shuffling..." << endl;

    t.shuffle();

    t.showSongList();

    cout << "Shuffled" << endl;

    cout << "Sorting..." << endl;

    t.sortSongList();

    t.showSongList();

    cout << "Sorted" << endl;

    cout<< "Rem Mem " <<t.getRemainingMemory() << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    result = t.addSong(s1);
    cout << "add result = " << result << endl;

    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    p.showSongList();
    p.clearMemory();

    cout << "Cleared! " << endl;
    p.showSongList();
}