SRCS=6chapter.cpp 12chapter.cpp 10chapter.cpp 14chapter.cpp 3chapter.cpp 2chapter.cpp 7chapter.cpp
OUTS=6a.out 12a.out 10a.out 14a.out 3a.out 2a.out 7a.out
all: $(OUTS)

6a.out:6chapter.cpp
	g++ -std=c++11 -Wall -o 6a.out 6chapter.cpp
12a.out:12chapter.cpp
	g++ -std=c++11 -Wall -o 12a.out 12chapter.cpp
10a.out:10chapter.cpp
	g++ -std=c++11 -Wall -o 10a.out 10chapter.cpp
14a.out:14chapter.cpp
	g++ -std=c++11 -Wall -o 14a.out 14chapter.cpp
3a.out:3chapter.cpp
	g++ -std=c++11 -Wall -o 3a.out 3chapter.cpp
2a.out:2chapter.cpp test.cpp test.h
	g++ -std=c++11 -Wall -o 2a.out 2chapter.cpp test.cpp
7a.out:7chapter.cpp
	g++ -std=c++11 -Wall -o 7a.out 7chapter.cpp

clean:
	rm -f *.out
