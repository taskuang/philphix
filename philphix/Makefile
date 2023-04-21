CC = gcc
CFLAGS = -g -Wall -std=c99 -c
LDFLAGS = -g -Wall

BUILD_DIR = ./build

# A phony target is one that is not really the name of a file;
# rather it is just a name for a recipe to be executed when you make an explicit request.
# You can read more about them here: https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html
.PHONY : all test clean

all : philphix

philphix : philphix.o hashtable.o
	$(CC) $(LDFLAGS) -o philphix $(BUILD_DIR)/philphix.o $(BUILD_DIR)/hashtable.o

philphix.o : src/philphix.c src/philphix.h src/hashtable.h build_dir
	$(CC) $(CFLAGS) src/philphix.c -o $(BUILD_DIR)/philphix.o

hashtable.o : src/hashtable.c src/hashtable.h build_dir
	$(CC) $(CFLAGS) src/hashtable.c -o $(BUILD_DIR)/hashtable.o

build_dir :
	mkdir -p $(BUILD_DIR)

clean :
	rm -f $(BUILD_DIR)/*.o philphix tests/sanity/testOutput

# Make sure you leave testpassedall as the last thing in this line. You can add your own custom tests before it.
test: testbasic testedge testalpha testcap testempty testspace testnumbers testdictline testinputline testbinary testlonginput testlongdict testlargedict testpassedall

testbasic: clean philphix
	touch tests/sanity/testOutput
	rm tests/sanity/testOutput
	@echo "================Running Program...================="
	cat tests/sanity/test | ./philphix tests/sanity/replace > tests/sanity/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/sanity/testOutput tests/sanity/reference
	@echo "-----------------------None!-----------------------"
	@echo

testedge: philphix
	@echo "Making the test files!"
	@echo
	@echo "A A" > null.txt
	@echo "================Running Program...================="
	cat philphix | ./philphix null.txt > newphilphix
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff philphix newphilphix
	@echo "-----------------------None!-----------------------"
	@rm -f null.txt newphilphix
	@echo

testalpha: clean philphix
	touch tests/alpha/testOutput
	rm tests/alpha/testOutput
	@echo "================Running Program...================="
	cat tests/alpha/test | ./philphix tests/alpha/replace > tests/alpha/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/alpha/testOutput tests/alpha/reference
	@echo "-----------------------None!-----------------------"
	@echo

testcap: clean philphix
	touch tests/cap/testOutput
	rm tests/cap/testOutput
	@echo "================Running Program...================="
	cat tests/cap/test | ./philphix tests/cap/replace > tests/cap/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/cap/testOutput tests/cap/reference
	@echo "-----------------------None!-----------------------"
	@echo

testempty: clean philphix
	touch tests/empty/testOutput
	rm tests/empty/testOutput
	@echo "================Running Program...================="
	cat tests/empty/test | ./philphix tests/empty/replace > tests/empty/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/empty/testOutput tests/empty/reference
	@echo "-----------------------None!-----------------------"
	@echo

testspace: clean philphix
	touch tests/spaces/testOutput
	rm tests/spaces/testOutput
	@echo "================Running Program...================="
	cat tests/spaces/test | ./philphix tests/spaces/replace > tests/spaces/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/spaces/testOutput tests/spaces/reference
	@echo "-----------------------None!-----------------------"
	@echo

testnumbers: clean philphix
	touch tests/numbers/testOutput
	rm tests/numbers/testOutput
	@echo "================Running Program...================="
	cat tests/numbers/test | ./philphix tests/numbers/replace > tests/numbers/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/numbers/testOutput tests/numbers/reference
	@echo "-----------------------None!-----------------------"
	@echo

testdictline: clean philphix
	touch tests/dictline/testOutput
	rm tests/dictline/testOutput
	@echo "================Running Program...================="
	cat tests/dictline/test | ./philphix tests/dictline/replace > tests/dictline/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/dictline/testOutput tests/dictline/reference
	@echo "-----------------------None!-----------------------"
	@echo

testinputline: clean philphix
	touch tests/inputline/testOutput
	rm tests/inputline/testOutput
	@echo "================Running Program...================="
	cat tests/inputline/test | ./philphix tests/inputline/replace > tests/inputline/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/inputline/testOutput tests/inputline/reference
	@echo "-----------------------None!-----------------------"
	@echo

testbinary: clean philphix
	touch tests/binary/testOutput
	rm tests/binary/testOutput
	@echo "================Running Program...================="
	cat tests/binary/test | ./philphix tests/binary/replace > tests/binary/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/binary/testOutput tests/binary/reference
	@echo "-----------------------None!-----------------------"
	@echo

testlonginput: clean philphix
	touch tests/longinput/testOutput
	rm tests/longinput/testOutput
	@echo "================Running Program...================="
	cat tests/longinput/test | ./philphix tests/longinput/replace > tests/longinput/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/longinput/testOutput tests/longinput/reference
	@echo "-----------------------None!-----------------------"
	@echo

testlongdict: clean philphix
	touch tests/longdict/testOutput
	rm tests/longdict/testOutput
	@echo "================Running Program...================="
	cat tests/longdict/test | ./philphix tests/longdict/replace > tests/longdict/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/longdict/testOutput tests/longdict/reference
	@echo "-----------------------None!-----------------------"
	@echo

testlargedict: clean philphix
	touch tests/largedict/testOutput
	rm tests/largedict/testOutput
	@echo "================Running Program...================="
	cat tests/largedict/test | ./philphix tests/largedict/replace > tests/largedict/testOutput
	@echo "================Program Finished!=================="
	@echo ""
	@echo "Difference between test output and reference output"
	@echo "---------------------------------------------------"
	@diff tests/largedict/testOutput tests/largedict/reference
	@echo "-----------------------None!-----------------------"
	@echo

testpassedall:
	@echo "You have passed all of the tests!"
