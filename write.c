#include "pipe.h"

/* burada pipe'a bir string verilecek
 * o string pipe'lar araciligi ile threadlere ulasacak*/

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	
	return (i);
}

void pipeWrite(t_pipe *dataPipe)
{
	close(dataPipe->fd[0]); // okuma ucunu kapattim
	char *str = "merhaba ben main process threadler'e sesleniyorum";

	write(dataPipe->fd[1], str, ft_strlen(str));

	close(dataPipe->fd[1]);
}