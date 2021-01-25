#include <stdio.h>
#include <string.h>

#define BUFLEN 168

/* char *prePendTheMsg(char *dest, char *src)

    Before first use of prePendTheMsg(), char *dest must be initialized with 0's
    for example through memset().

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



char * prePendTheMsg(char *dest, char *src, int bfl)   // first in last out ==> pre-pends string to already existing string
{                                                      // assuming a string goes from left to right
    int mxSL, currSL, remainSL, incomingSL, rightShifts;
    char *posStartStr, *endDest, *putHere, *cPtB, *cPtA;

    if(bfl <= 1)
        return(NULL);


    putHere = (char *) NULL;
    endDest = dest + (bfl-1); // endDest points to rightmost '\0' dest(ination string)

    posStartStr = dest;
    while((*posStartStr == 0) && (posStartStr != endDest))
        ++posStartStr;

    if (src == NULL)
        return(posStartStr); // if string-to-prepend is NULL, then just return pointer to startPos of characters in 'dest'

    rightShifts= 0;
    mxSL       = bfl-1;
    currSL     = strlen(posStartStr);
    remainSL   = mxSL - currSL;
    incomingSL = strlen(src);

    if(incomingSL > remainSL)
    {
        rightShifts = incomingSL - remainSL;

        cPtA = endDest - 1;
        cPtB = cPtA - rightShifts;

        while(cPtB >= dest)
            *cPtA-- = *cPtB--;

        putHere = dest;
    }
    else
        putHere = posStartStr - incomingSL;

    cPtA = putHere;
    cPtB  = src;

    while(*cPtB && (cPtA != endDest)) // (cPtA != endDest) because src can be longer than dest
        *cPtA++ = *cPtB++;

    return(putHere);
}




int main()
{
    char buf[BUFLEN], txt[BUFLEN], *p;

    memset(buf, 0, BUFLEN);

    strcpy(txt, "1) This string will be added first but will end as last.\n");
    p = prePendTheMsg(buf, txt, BUFLEN);

    printf("\nString added:%sContent of destination is now:\n%s", txt, p);

    strcpy(txt, "2) This is the second string.\n");
    p = prePendTheMsg(buf, txt, BUFLEN);
    printf("\nString added:%sContent of destination is now:\n%s", txt, p);

    strcpy(txt, "3) Finally the last string. If there is not enough space in destination,\n   previously added strings will be shortenend.\n");
    p = prePendTheMsg(buf, txt, BUFLEN);
    printf("\nString added:%sContent of destination is now:\n%s", txt, p);

    p = prePendTheMsg(buf, NULL, BUFLEN);
    printf("\n\n\nbuf=\n%s\n", p);

    return(0);
}
