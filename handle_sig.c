#include <unistd.h>
/**
 * sigint_handler - handles terminate signal
 * @s:the signal number
 */
void sigint_handler(int __attribute__((unused)) s)
{
	write(1, "\n($) ", 5);
}
