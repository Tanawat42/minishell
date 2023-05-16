# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 21:14:32 by tjukmong          #+#    #+#              #
#    Updated: 2023/04/20 22:49:51 by tjukmong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Static Libaray name.
NAME		= files_util.a

# Header file include dirrectory.
HEAD		= .

# To test the libaray, create a file with the same name as TESTFILE and play
# arround with it :D (output executable will be named after this option with
# .out extension, with .log file created, for log file obviously).
TESTFILE	= main.c
LOGFILE		= ${TESTFILE:.c=.log}

# Source dirrectory.
DIRSRC		= ./

# Source files.
SRC			= files_util.c ft_chdir.c ft_getpath.c ft_getpwd.c ft_pathenv.c

# Object files (similar to DLLs)
# Path to object files
SRCS			= ${addprefix ${DIRSRC}, ${SRC}}
# Source objects (replaces .c with .o).
SRCOBJ			= ${SRCS:.c=.o}

# C Compiler.
CC				= gcc
# CC Flags
CFLAGS			= -Wall -Wextra -Werror

# Remove files.
RM				= rm -f

# Link sources, if not specified (default).
all:			${NAME}

# Link mandatory.
${NAME}:		$(SRCOBJ)
				ar rc ${NAME} ${SRCOBJ}

# Tester file
test:			all
	${CC} ${CFLAGS} ${TESTFILE} ${NAME} -o ${TESTFILE:.c=.out}
	@ echo "\033[1;36m========-[ Execution output ]-========\033[0;37m"	   > ${LOGFILE}
	@ exec ${DIRSRC}${TESTFILE:.c=.out} | cat -e						  >> ${LOGFILE}
	@ echo "\n\033[1;35m============-[ Valgrind ]-============\033[0;37m" >> ${LOGFILE}
	@ valgrind ${DIRSRC}${TESTFILE:.c=.out} -qs --leak-check=full		  >> ${LOGFILE} 2>&1
	@ echo "\033[1;32m===========-[ Norm errors ]-==========\033[0;37m"	  >> ${LOGFILE}
	@ norminette ${DIRSRC} | grep "Error" | cat							  >> ${LOGFILE}
	@ echo "\033[1;32m======================================\033[0;37m"	  >> ${LOGFILE}
	@ less -R ${LOGFILE}

readlog:
	less -R ${LOGFILE}

# Annnddd Lastly...
clean:
				${RM} ${SRCOBJ}

fclean:			clean
				${RM} ${NAME} ${TESTFILE:.c=.out} ${LOGFILE}

re:				fclean all

.PHONY:			all test clean fclean re
