#include "pipe.h"

static void thread_malloc(t_pipe *data)
{
	//printf("\nmalloc girdi bro\n");
	data->threadData = (t_thread *)malloc(THNBR + 1);
}

void dataProcess(t_pipe *dataPipe)
{
	//printf("\nprocess girdi bro\n");
	for (int i = 0; i < THNBR; i++)
		dataPipe->threadData[i].dataPipe = dataPipe;
}

void threadCreate(t_pipe *dataPipe)
{
	//printf("\ncreate girdi bro\n");
	for (int i = 0; i < THNBR; i++)
		pthread_create(&dataPipe->threadData[i].t1, NULL, pipeRead, &dataPipe->threadData[i]), dataPipe->threadData[i].threadNbr = i + 1, printf("[%d] numarali thread aktif\n", i + 1); 
}

void waitThread(t_pipe *dataPipe)
{
	//printf("\nwait girdi bro\n");
	for (int i = 0; i < THNBR; i++)
		pthread_join(dataPipe->threadData[i].t1, NULL);
}

void mutexCreate(t_pipe *dataPipe)
{
	pthread_mutex_init(&dataPipe->mutex, NULL);
}

void mutexDestroy(t_pipe *dataPipe)
{
	pthread_mutex_destroy(&dataPipe->mutex);
}

int main(int ac, char **av)
{
	t_pipe	dataPipe;
	int	pid;

	if (pipe(dataPipe.fd) == -1)
		printf("pipe error\n"), exit(1);
	pid = fork();
	if (pid == 0)
	{
		printf("fork calisiyor\n"), printf("threadler olusturuluyor\n");
		thread_malloc(&dataPipe);
		dataProcess(&dataPipe);
		threadCreate(&dataPipe);
		waitThread(&dataPipe);
		exit(0);
	}

	pipeWrite(&dataPipe);
	waitpid(pid, 0, 0);
}