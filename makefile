final: UtPodDriver.o UtPod.o Song.o
	g++ -o final UtPodDriver.o UtPod.o Song.o
UtPodDriver.o: UtPodDriver.cpp UtPod.h Song.h
	g++ -std=c++11 -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -std=c++11 -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
