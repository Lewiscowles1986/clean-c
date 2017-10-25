CC	= gcc
CFLAGS	= -g -O2

PKGNAME	= app
OBJS	= $(PKGNAME).o utils.o
LDFLAGS	= 
LIBS	= -lm

all: $(PKGNAME)

$(PKGNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(PKGNAME) $(OBJS) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o core a.out make.log \#*\# $(PKGNAME) $(OBJS)
