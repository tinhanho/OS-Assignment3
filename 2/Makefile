example_no_lock:
	@sed -i '53s/.*//' example.c
	@sed -i '55s/.*//' example.c
	@sed -i '69s/.*//' example.c
	@sed -i '71s/.*//' example.c	
	@gcc -o example.out example.c
	@i=1; while [ $$i -le 10 ]; do \
		./example.out;	\
		i=$$((i + 1)); \
	done
	@./judge.out e
	@rm -f example.out
	@rm -f 2.txt

example_with_lock:
	@sed -i '53s/.*/pthread_spin_lock(\&lock);/' example.c
	@sed -i '55s/.*/pthread_spin_unlock(\&lock);/' example.c
	@sed -i '69s/.*/pthread_spin_lock(\&lock);/' example.c
	@sed -i '71s/.*/pthread_spin_unlock(\&lock);/' example.c	
	@gcc -o example.out example.c
	@i=1; while [ $$i -le 10 ]; do \
		./example.out;	\
		i=$$((i + 1)); \
	done
	@./judge.out e
	@rm -f example.out
	@rm -f 2.txt

judge1:
	@gcc -o 2.out 2_1.c
	@./2.out
	@./judge.out 1
	@rm -f 2.out
	@rm -f 2.txt

judge2:
	@gcc -o 2.out 2_2.c
	@i=1; while [ $$i -le 10 ]; do \
		./2.out; \
		i=$$((i + 1)); \
	done
	@./judge.out 2
	@rm -f 2.out
	@rm -f 2.txt

diff:
	@gcc -o 2.out 2_1.c
	@./2.out
	@git diff --word-diff  2_ans.txt 2.txt || true
	@rm -f 2.out
	@rm -f 2.txt