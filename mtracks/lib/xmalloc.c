#include "mtracks_stdlib.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Allocate a buffer. Quit the program if there is insufficient memory.
 * @param len [in] The length of the buffer in bytes.
 * @return The allocated and initialized buffer.
 * @remarks Unlike malloc(3), xmalloc will zero the buffer prior to returning.
 */
void *
xmalloc(
	size_t len)
{
	void *ptr = malloc(len);

	if (!ptr) {
		fprintf(stderr, "ERROR: Out of memory.\n");
		exit(1);
	}

	memset(ptr, '\0', len);

	return (ptr);
}
