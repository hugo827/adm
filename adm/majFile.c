#include "Header.h"


void majFile(Client* pDebutClient) {
	Client* pFile = pDebutClient;

	while (pFile != NULL) {
		pFile->tempsPasseFile++;
		pFile->tempsPasseSystem++;
		pFile = pFile->pSuivClient;
	}
	
}