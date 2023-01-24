C:=gcc
BIN:=watson-sender
SRC:=$(wildcard *.c)
OBJ:=$(SRC:.c=.o)
LDFLAGS:= -liotp-as-device -lpaho-mqtt3as -lblobmsg_json -lubox -lubus -largp

.PHONY: all clean 

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN) $(OBJ)

