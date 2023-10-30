SRCS = $(wildcard Exercise9_?.c)

PROGS = $(patsubst %.c,%,$(SRCS))

CFLAGS+=-Wall -g

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS)  -o $@ $< -lm

clean:
	rm -f *~
	rm -f $(PROGS)


# SRCS = $(wildcard Exercise9_?.c)
# PROGS = $(patsubst %.c,%,$(SRCS))
# CFLAGS += -Wall -g
# LIBS = -lm

# all: $(PROGS)

# %: %.c list.c
# 	$(CC) $(CFLAGS) -o $@ $< list.c $(LIBS)

# clean:
# 	rm -f *~
# 	rm -f $(PROGS)