OPT=
CFLAGS=-std=c18 -Wall

readme:
	less README.txt

%.bin : %.c
	$(CC) $(CFLAGS) $(OPT) $^ -o $@

%.bin-g : %.c
	$(CC) $(CFLAGS) $(OPT) -g $^ -o $@

%.bin-san : %.c
	$(CC) $(CFLAGS) $(OPT) -g -fsanitize=address $^ -o $@


%.run : %.bin
	./$(*F).bin

%.run-san : %.bin-san
	./$(*F).bin-san

%.run-g : %.bin-g
	./$(*F).bin-g

%.ddd : %.bin-g
	ddd --command prolog.gdb $(*F).bin-g &

%.ddd-san : %.bin-san
	ddd --command prolog.gdb $(*F).bin-san &

%.run-vg : %.bin-g
	valgrind --leak-check=full ./$(*F).bin-g

clean:
	rm -f *.o *.bin*
