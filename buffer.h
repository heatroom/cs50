
#ifndef BUFFER
#define BUFFER
#endif

#ifndef BUFFER_DEFAULT_SIZE
#define BUFFER_DEFAULT_SIZE 64
#endif

/*
 * Buffer struct 
 */

typedef struct {
	size_t len;
	char *alloc;
	char *data;
} buffer_t;


//prototypes

buffer_t *
buffer_new();

buffer_t *
buffer_new_with_size(size_t n);

buffer_t *
buffer_new_with_string_length(char *str, size_t len);

buffer_t *
buffer_new_with_copy(char *str);