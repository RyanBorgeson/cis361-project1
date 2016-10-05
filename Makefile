all:
	gcc Ceaser.c -o Ceaser -w
	./Ceaser 0 FEATHER data.txt encrypt_out.txt
	./Ceaser 1 FEATHER encrypt_out.txt decrypt_out.txt