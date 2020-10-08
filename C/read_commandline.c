#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fgets : string
// fgetc : char

int main(int argc, char *argv[]){

	FILE *fp;
	char cmdbuf[256];
	char buf[256];
	char srcstr[64];
	char outstr[64];

    snprintf(cmdbuf, sizeof(cmdbuf), "cat /tmp/surveyGband | grep \"%s\" | awk -F \" \" \'{print $4}\'", srcstr);
    if((fp = popen(cmdbuf, "r")) != NULL)
    {
        fgets(outstr, sizeof(outstr), fp);
        outstr[strlen(outstr)-1] = '\0';
        pclose(fp);
    }

	sprintf(buf, "echo \"SiteSurvey %s\" >> /storage/YHDAVID", outstr);
	system(buf);
}

/*****************************************************************************/
/**
*  @brief sysinteract
*  @param output output.
*  @param outputlen output of len.
*  @param fmt format
*  @return The results: cmd status
*/
// T_INT32 sysinteract(T_CHAR *output, T_INT32 outputlen, T_CHAR *fmt, ...) 
// {
//     static char cmd_for_sysinteract[256];
//     FILE *pipe;
//     int c;
//     int i;
//     va_list ap;

//     va_start(ap, fmt);
//     vsnprintf(cmd_for_sysinteract, sizeof(cmd_for_sysinteract), fmt, ap);
//     va_end(ap);

//     memset(output, 0, outputlen);

//     if((pipe = popen(cmd_for_sysinteract, "r")) == NULL)
//     {
//         goto err;
//     }

//     for(i = 0; ((c = fgetc(pipe)) != EOF) && (i < outputlen - 1); i++)
//     {
//         output[i] = (char) c;
//     }
//     output[i] = '\0';

//     pclose(pipe);

//     if(strlen(output) == 0)
//     {
//         goto err;
//     }

//     return 0;

// err:
//     strcpy(output, "---");
//     return -1;
// }