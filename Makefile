BUILD_LOCATE=./build
SRC_LOCATE=./src
TEST_LOCATE=./test

OUTPUT_FILE=compiler

CFLAGS=-Wall

all: common lexer parser checker gen main
	
	mv *.o $(BUILD_LOCATE)
	gcc -o $(BUILD_LOCATE)/$(OUTPUT_FILE) $(BUILD_LOCATE)/*.o 
	rm -rf $(BUILD_LOCATE)/*.o

common:
	gcc -c $(SRC_LOCATE)/common/*.c $(CFLAGS)

lexer:
	gcc -c $(SRC_LOCATE)/lexer/*.c $(CFLAGS)

parser:
	gcc -c $(SRC_LOCATE)/parser/*.c $(CFLAGS)

checker:
	gcc -c $(SRC_LOCATE)/checker/*.c $(CFLAGS)

gen:
	gcc -c $(SRC_LOCATE)/gen/*.c $(CFLAGS)

main:
	gcc -c $(SRC_LOCATE)/main.c $(CFLAGS)

run:
	$(BUILD_LOCATE)/$(OUTPUT_FILE)

clean:
	rm -rf $(BUILD_LOCATE)/*