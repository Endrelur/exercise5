#include "utility.h"

int main(int argc, char const *argv[])
{
    // char *buffer = "";
    // char *buffer = "&";
    char *buffer = "<script>&&&</script>";

    buffer = encode(buffer);
    if (buffer == NULL)
        return -1;

    printf("%s\n", buffer);
    free(buffer);

    return 0;
}