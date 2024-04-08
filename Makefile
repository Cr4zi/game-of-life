CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lraylib -lm

SRCDIR = src
INCDIR = include
BUILDDIR = build

SRCFILES = $(wildcard $(SRCDIR)/*.c)
OBJFILES = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCFILES))

EXECUTABLE = game-of-life

all: $(BUILDDIR)/$(EXECUTABLE)

$(BUILDDIR)/$(EXECUTABLE): $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXECUTABLE)

