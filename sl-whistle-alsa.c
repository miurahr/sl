/*========================================
 *    sl-whistle-linux.c: 
 *       SL whistle helper for linux
 *	Copyright 2014
 *                Hiroshi Miura
 *		  (miurahr@acm.org)
 *	Last Modified: 2014/ 3/ 27
 *========================================
 */

/* Audio file is CC0 license. shared on
 * http://www.freesound.org/people/Bidone/sounds/71778/
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <alsa/asoundlib.h>

/* fixme */
/* here is quick and dirty implementation
 * it should be implemented using asoundlib API
 */
void
do_play_whistle(void) {
    char *const args[] = {"/usr/bin/aplay","-q","whistle.wav",NULL};
    execvp(args[0],args);
}

void
play_whistle(void) {
    int status;
    pid_t pid;

    if ((pid = fork())== 0){
        do_play_whistle();
    }
    waitpid(pid, &status, 0);
}

