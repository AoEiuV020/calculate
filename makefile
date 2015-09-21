include header.mk
n=d
#$(n).$(TAREXT):$(n).cpp
all:
	g++ -Wall -Wpedantic --std=c++11 --save-temps -o $(n).$(TAREXT) $(n).cpp
	#.$(PS)$(n).$(TAREXT) <txt
	.$(PS)txt|.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.ii *.o *.s *.$(TAREXT) *.d


