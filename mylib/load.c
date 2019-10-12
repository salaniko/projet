#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef WIN32
    #include <sys/types.h>
#endif

#define N 100


struct element
{
	struct noeud * fichier;
	struct element * suivant;
};
typedef struct element * Liste;

struct noeud
{
	char nom_fichier[N];
	Liste fils;
};
typedef struct noeud * Arborescence;


void load(Arborescence arbo, char racine[])
{
	

}


int main()
{
	
	return 0;
}
