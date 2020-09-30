#include <stdio.h>

__thread char one_byte_to_mess_up_alignment;
__thread __int128 large_int __attribute__((aligned(16)));
__int128 not_so_large_int = 42;

int main(void) {
    large_int = not_so_large_int; // Likely to use SSE instruction

    return 0;
}
