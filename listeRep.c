#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef WIN32
    #include <sys/types.h>
#endif

int isDirectory(const char *path) {
   	struct stat statbuf;
   	stat(path, &statbuf);
   	if (stat(path, &statbuf) != 0)
        return 0;
   	return S_ISDIR(statbuf.st_mode);
}

void lister(const char *nom_rep)
{
	
	DIR* rep = NULL;
	rep = opendir(nom_rep);

	struct dirent* fichierLu;

	if (rep == NULL)
	{
		printf("Dossier inexistant !\n");
		exit(1);
	}

	while ((fichierLu = readdir(rep)) != NULL)
	{
		char *tmp = strdup(nom_rep);
    	strcat(tmp, "/");	
    	strcat(tmp, fichierLu->d_name);

		if (fichierLu->d_name[0] != '.') {

    		if (isDirectory(tmp) == 1) {

    			lister(tmp);
			} else {
				printf ("%s\n", tmp);
			}
  		}
	}

	if(closedir(rep) == -1)
	{
		printf("Problème avec la fermeture du dossier !\n");
		exit(-1);
	}

}


int main(int argc, char const *argv[])
{
	
	lister(&(*argv[1]));

	return 0;
}