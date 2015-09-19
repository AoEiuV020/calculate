include header.mk
n=c
$(n).$(TAREXT):$(n).cpp
	g++ -Wall -Wpedantic --std=c++11 --save-temps -o $(n).$(TAREXT) $(n).cpp
	.$(PS)$(n).$(TAREXT) <txt
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.ii *.o *.s *.$(TAREXT) *.d


