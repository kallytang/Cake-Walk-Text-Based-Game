


CXX =  g++
CXXFLAGS = -std=gnu++11 
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g 
LDFLAGS = -lboost_date_time

OBJS = main.o BakingSoda.o BlackCat.o Character.o Coin.o Corn.o Eggs.o FarmField.o Flour.o Game.o InventoryItem.o Key.o Kitchen.o LivingRoom.o Neighborhood.o Porch.o RivalCat.o RivalHouse.o Space.o WhiteCat.o

SRCS = main.cpp BakingSoda.cpp BlackCat.cpp Character.cpp Coin.cpp Corn.cpp Eggs.cpp FarmField.cpp Flour.cpp Game.cpp InventoryItem.cpp Key.cpp Kitchen.cpp LivingRoom.cpp Neighborhood.cpp Porch.cpp RivalCat.cpp RivalHouse.cpp Space.cpp WhiteCat.cpp


HEADERS=  BakingSoda.hpp BlackCat.hpp Character.hpp Coin.hpp Corn.hpp Eggs.hpp FarmField.hpp Flour.hpp Game.hpp InventoryItem.hpp Key.hpp Kitchen.hpp LivingRoom.hpp Neighborhood.hpp Porch.hpp RivalCat.hpp RivalHouse.hpp Space.hpp WhiteCat.o







#target: dependencies 
#	rule to build 
#

runGame:  ${OBJS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${SRCS} -o runGame

${OBJS}:${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


.PHONY : clean 
clean : 
	-rm  $(OBJS)
	-rm runGame



