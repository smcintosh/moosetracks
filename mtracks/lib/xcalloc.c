#include "libutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Allocate a buffer. Quit the program if there is insufficient memory.
 * @param count [in] The number of elements to allocate.
 * @param size [in] The size of each element.
 * @return The allocated and initialized buffer.
 */
void *
xcalloc(
	size_t count,
	size_t size)
{
	void *ptr = calloc(count, size);

	if (!ptr) {
		fprintf(stderr, "ERROR: Out of memory.\n");
		exit(1);
	}

	return (ptr);
}
