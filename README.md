# prepend_string

The main function of prepend_string.c calls prePendTheMsg()



/* char *prePendTheMsg(char *dest, char *src)

    Before first use of prePendTheMsg(), char *dest must be initialized with 0's
    for example through memset(), see main().

    After each call to prePendTheMsg() it will add char *src to char *dest, *dest will be
    filled with the content of char *src from right to left. So all free spaces (0's) are
    on the left side of char *dest.

    If after one or more calls to prePendTheMsg() the string dest is full (no more 0's left,
    except the 0-terminator at the far right of dest), and one again calls prePendTheMsg()
    there is obviously no more space left for prepending src into dest. In that case the
    whole content of dest will be moved/shifted to the right. The number of "right-shifts"
    depends on the length of src (the string to prepend).

    prePendTheMsg() the message returns a char-pointer which points to the first non-zero-character
    of dest
*/
