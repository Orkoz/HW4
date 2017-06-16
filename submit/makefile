# This is a Makefile for project
CCC = g++
CXXFLAGS = -g -Wall
CXXLINK = $(CCC)
OBJS = Course.o CS_Course.o EE_Course.o main.o CS_Course.h Person.o StArray.o Course.h CS_Course.h Student.o CS_Course.h

all: students

students: $(OBJS) 
	$(CXXLINK) -o students $(OBJS)

Course.o: Course.cpp Course.h Proj.h
CS_Course.o: CS_Course.cpp Course.h Proj.h CS_Course.h
EE_Course.o: EE_Course.cpp Course.h Proj.h EE_Course.h
main.o: main.cpp Proj.h StArray.h Student.h Person.h EE_Course.h Course.h CS_Course.h
Person.o: Person.cpp Person.h Proj.h
StArray.o: StArray.cpp StArray.h Proj.h Student.h Person.h EE_Course.h Course.h CS_Course.h
Student.o: Student.cpp Student.h Person.h Proj.h EE_Course.h Course.h CS_Course.h