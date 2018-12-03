.SUFFIXES: .c .cpp

CC = gcc
CXX = g++

.c:
	$(CC) -I$(INCDIR) $(CFLAGS) $< $(GL_LIBS) -o $@
.cpp:
	$(CXX) -Wall -Wunused $< -o $@ -I /usr/include/opencv -L /usr/lib -lopencv_video -lopencv_imgproc -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_shape
