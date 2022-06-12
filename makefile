files := main arg_loader common cesar
out := cesar

testfile := test/test.txt
testout := test/test
fcmp := test/fcmp/fcmp

all: clean $(files) link tclean trun

clean:
	@echo Clean UP...
	@rm -f bin/*
	@rm -f $(out)

$(files):
	@echo Compiling $@...
	@g++ src/$@.cpp -o bin/$@.o -c -std=c++2a

link:
	@echo Linking...
	@g++ bin/*.o -o $(out) -std=c++2a

tclean:
	@echo Clean UP tests...
	@rm -f test/*.o 

trun:
	@echo Test1...
	@./$(out) -c $(testfile) -o $(testout)1.o
	@./$(out) -d $(testout)1.o -o $(testout)1.d.o
	@./$(fcmp) $(testfile) $(testout)1.d.o
	@./$(out) -c $(testfile) -o $(testout)1.bin.o -b
	@./$(out) -d $(testout)1.bin.o -o $(testout)1.bin.d.o -b
	@./$(fcmp) $(testfile) $(testout)1.bin.d.o
	@echo Test2...
	@./$(out) --code $(testfile) -o $(testout)2.o -s 4
	@./$(out) --decode $(testout)2.o -o $(testout)2.d.o -s 4
	@./$(fcmp) $(testfile) $(testout)2.d.o
	@./$(out) --code $(testfile) -o $(testout)2.bin.o -s 4 -b
	@./$(out) --decode $(testout)2.bin.o -o $(testout)2.bin.d.o -s 4 -b
	@./$(fcmp) $(testfile) $(testout)2.bin.d.o
	@echo Test3...
	@./$(out) -c $(testfile) -o $(testout)3.o -n 1
	@./$(out) -d $(testout)3.o -o $(testout)3.d.o -n 1
	@./$(fcmp) $(testfile) $(testout)3.d.o
	@./$(out) -c $(testfile) -o $(testout)3.bin.o -n 1 -b
	@./$(out) -d $(testout)3.bin.o -o $(testout)3.bin.d.o -n 1 -b
	@./$(fcmp) $(testfile) $(testout)3.bin.d.o
	@echo Test4...
	@./$(out) --code $(testfile) -o $(testout)4.o --shift 4 --incrementation 4
	@./$(out) --decode $(testout)4.o -o $(testout)4.d.o --shift 4 --incrementation 4
	@./$(fcmp) $(testfile) $(testout)4.d.o
	@./$(out) --code $(testfile) -o $(testout)4.bin.o --shift 4 --incrementation 4 -b
	@./$(out) --decode $(testout)4.bin.o -o $(testout)4.bin.d.o --shift 4 --incrementation 4 -b
	@./$(fcmp) $(testfile) $(testout)4.bin.d.o
	@echo Test5...
	@./$(out) -c $(testfile) -o $(testout)5.o -p "pssw"
	@./$(out) -d $(testout)5.o -o $(testout)5.d.o -p "pssw"
	@./$(fcmp) $(testfile) $(testout)5.d.o
	@./$(out) -c $(testfile) -o $(testout)5.bin.o -p "pssw" -b
	@./$(out) -d $(testout)5.bin.o -o $(testout)5.bin.d.o -p "pssw" -b
	@./$(fcmp) $(testfile) $(testout)5.bin.d.o
	@echo Test6...
	@./$(out) --code $(testfile) -o $(testout)6.o -s 4 --password "pssw"
	@./$(out) --decode $(testout)6.o -o $(testout)6.d.o -s 4 --password "pssw"
	@./$(fcmp) $(testfile) $(testout)6.d.o
	@./$(out) --code $(testfile) -o $(testout)6.bin.o -s 4 --password "pssw" -b
	@./$(out) --decode $(testout)6.bin.o -o $(testout)6.bin.d.o -s 4 --password "pssw" -b
	@./$(fcmp) $(testfile) $(testout)6.bin.d.o
	@echo Test7...
	@./$(out) -c $(testfile) -o $(testout)7.o -n 4 -p "pssw"
	@./$(out) -d $(testout)7.o -o $(testout)7.d.o -n 4 -p "pssw"
	@./$(fcmp) $(testfile) $(testout)7.d.o
	@./$(out) -c $(testfile) -o $(testout)7.bin.o -n 4 -p "pssw" -b
	@./$(out) -d $(testout)7.bin.o -o $(testout)7.bin.d.o -n 4 -p "pssw" -b
	@./$(fcmp) $(testfile) $(testout)7.bin.d.o
	@echo Test8...
	@./$(out) --code $(testfile) -o $(testout)8.o -s 4 -n 4 --password "pssw"
	@./$(out) --decode $(testout)8.o -o $(testout)8.d.o -s 4 -n 4 --password "pssw"
	@./$(fcmp) $(testfile) $(testout)8.d.o
	@./$(out) --code $(testfile) -o $(testout)8.bin.o -s 4 -n 4 --password "pssw" -b
	@./$(out) --decode $(testout)8.bin.o -o $(testout)8.bin.d.o -s 4 -n 4 --password "pssw" -b
	@./$(fcmp) $(testfile) $(testout)8.bin.d.o
