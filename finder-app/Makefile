cc = gcc


writer: writer.o
	$(CROSS_COMPILE)$(cc) $^ -o $@

writer.o: writer.c
	$(CROSS_COMPILE)$(cc) -c $^ -o $@ 

.PHONY: clean

clean:
	rm -f writer.o
	rm -f writer
