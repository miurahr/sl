/*========================================
 *    sl-whistle-beep.c: 
 *       SL whistle generic helper
 *	Copyright 2014
 *                Hiroshi Miura
 *		  (miurahr@acm.org)
 *	Last Modified: 2014/ 3/ 27
 *========================================
 */

#include <curses.h>

void
play_whistle(void) {
    int i;

    for (i=0; i < 100; i++) {
        beep();
        usleep(1000);
    }
}
