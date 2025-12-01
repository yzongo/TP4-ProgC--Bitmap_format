main : test.o  imageRGB.o main.o BMPFile_teacher.o BMPFile.o 
	gcc test.o imageRGB.o   BMPFile_teacher.o main.o BMPFile.o -o main

test.o : test.c imageRGB.h BMPFile.h
	gcc -c  test.c

imageRGB.o: imageRGB.c test.h BMPFile.h
	gcc -c  imageRGB.c

BMPFile.o : imageRGB.c test.h BMPFile.h
	gcc -c BMPFile.c

main.o : main.c test.h imageRGB.h BMPFile.h 
	gcc -c main.c 

