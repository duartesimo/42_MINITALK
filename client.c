#include "minitalk.h"

void	send_letter(pid_t pid, char letter)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((letter & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("ERROR: Invalid number of arguments!\n");
		ft_printf("Try: ./client [server PID] [message]\n");
		exit(1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("Invalid PID\n");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	validate_args(argc, argv);
	pid = (pid_t)ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_letter(pid, *str);
		str++;
	}
	send_letter(pid, '\n');
	return (0);
}
