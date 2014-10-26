#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

//Allocate a new buffer with BUFFER_DEFAULT_SIZE.
buffer_t *
buffer_new() {
	return buffer_new_with_size(BUFFER_DEFAULT_SIZE);
}

//ALLOCATE a new buffer with `n` bytes.
buffer_t *
buffer_new_with_size(size_t n) {
	buffer_t *self = malloc(sizeof(buffer_t));
	if (!self) return NULL;
	self->len = n;
	self->data = self->alloc = calloc(n+1, 1);
	return self;
}

// Allocate a new buffer with `string` and `length`.
buffer_t *
buffer_new_with_string_length(char *str, size_t len) {
	buffer_t *self = malloc(sizeof(buffer_t));
	if(!self) return NULL;
	self->len = len;
	self->data = self->alloc = str;
	return self;
}


buffer_t *
buffer_new_with_copy(char *str){
	buffer_t *self = malloc(sizeof(buffer_t));
	if(!self) return NULL;
	self->len = strlen(str);
	self->data = self->alloc = str;
	return self;
}

//return the buffer size
size_t buffer_size(buffer_t *buf) {
	return buf->len;
}

//return the buffer length
size_t buffer_length(buffer_t *buf) {
	return strlen(buf->data);
}

int main(int argc, char *argv[]) {
	buffer_t *buf0 = buffer_new();
	buffer_t *buf1 = buffer_new_with_size(1024);
	buffer_t *buf2 = buffer_new_with_string_length("i love xia huanjuan", 1024);
	printf("0. newly created default %lu length buffer.\n", buf0->len);
	printf("1. newly created %lu length buffer.\n", buf1->len);
	printf("2. newly created %lu length buffer, and it's content is \"%s\".\n", buf2->len, buf2->data);
}
