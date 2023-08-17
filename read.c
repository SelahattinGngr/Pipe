#include "pipe.h"

/* burada pipe'a verilen stringi threadler araciligi ile okuyacagiz */

void *pipeRead(void *_threadData)
{
	// sleep(1);
	t_thread *threadData;
	char tmp[100];

	threadData = (t_thread *)_threadData;
	close(threadData->dataPipe->fd[1]); // yazma ucunu kapattım;
	pthread_mutex_lock(&threadData->dataPipe->mutex);
	read(threadData->dataPipe->fd[0], tmp, sizeof(tmp));
	pthread_mutex_unlock(&threadData->dataPipe->mutex);
	printf("ben [%d] numarali thread main processden gelen mesaj: %s\n",threadData->threadNbr, tmp);
	close(threadData->dataPipe->fd[0]);
	return (NULL);
}