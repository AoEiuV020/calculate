include header.mk
n=m
#$(n).$(TAREXT):$(n).cpp
all:
	g++ -Wall -Wpedantic --std=c++11 --save-temps -o $(n).$(TAREXT) $(n).cpp
	.$(PS)$(n).$(TAREXT) <calc
	#.$(PS)txt|.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.ii *.o *.s *.$(TAREXT) *.d


