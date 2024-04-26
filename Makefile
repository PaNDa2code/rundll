CC=x86_64-w64-mingw32-gcc

rundll.exe: rundll.c 
	$(CC) $< -o $@

clean:
	rm rundll.exe -f
