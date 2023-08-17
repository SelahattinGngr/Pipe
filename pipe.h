#ifndef PIPE_H
#define PIPE_H
#define THNBR 4

#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "stdlib.h"

typedef struct s_thread
{
    int			threadNbr;
    pthread_t	t1;
	struct s_pipe *dataPipe;
} t_thread;

typedef struct s_pipe
{
	int fd[2];
	pthread_mutex_t mutex;
	t_thread *threadData;
} t_pipe;

size_t ft_strlen(char *str);
void pipeWrite(t_pipe *dataPipe);
void *pipeRead(void *_threadData);

#endif