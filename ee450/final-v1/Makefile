CC = g++
LDFLAGS = -lxnet -lnsl -lsocket
CFLAGS = -g -Wall

OBJ_FOLDER = obj/
SRC_FOLDER = src/
HDR_FOLDER = src/

ZIP_NAME = ee450_obilgic_session1.tar

main : $(OBJ_FOLDER)main.o $(OBJ_FOLDER)Captain.o $(OBJ_FOLDER)Major.o
	@echo "Linking object files:" $@
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_FOLDER)%.o : $(SRC_FOLDER)%.cpp $(HDR_FOLDER)%.h
	@echo "Compiling:" $@
	$(CC) $(CFLAGS) -c -o $@ $<

zip: clean
	@echo "Archiving the source code for submission"
	tar cvf $(ZIP_NAME) *
	gzip $(ZIP_NAME) *

clean:
	@echo "Cleaning all auto-generated files"
	rm -f main
	rm -f $(OBJ_FOLDER)*
	rm -f $(ZIP_NAME)
	rm -f *~
