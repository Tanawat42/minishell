# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 15:42:57 by tjukmong          #+#    #+#              #
#    Updated: 2023/04/09 15:48:56 by tjukmong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Static Libaray name.
NAME		= get_next_line.a

# Header file include dirrectory.
HEAD		= .

# To test the libaray, create a file with the same name as TESTFILE and play
# arround with it :D (output executable will be named after this option with
# .out extension, with .log file created, for log file obviously).
TESTFILE	= ./main.c
LOGFILE		= ${TESTFILE:.c=.log}

# Source dirrectory.
DIRSRC		= ./

# Source files.
SRC			= get_next_line.c get_next_line_utils.c

# BONUS	= 

# Object files (similar to DLLs)
# Path to object files
SRCS			= ${addprefix ${DIRSRC}, ${SRC}}
# BONUSES			= ${addprefix ${DIRSRC}, ${BONUS}}
# Source objects (replaces .c with .o).
SRCOBJ			= ${SRCS:.c=.o}
# Bonus objects (same thing as SRCOBJ, but for BONUS)
# BONUSOBJ		= ${BONUSES:.c=.o}

# C Compiler.
CC				= gcc
# CC Flags
CFLAGS			= -g -Wall -Wextra -Werror

# Remove files.
RM				= rm -f

# Link sources, if not specified (default).
all:			${NAME}

bonus:			all
				${CC} ${CFLAGS} -c ${BONUSES}
				ar rc ${NAME} ${BONUSOBJ}

# Link mandatory.
${NAME}:		$(SRCOBJ)
				ar rc ${NAME} ${SRCOBJ}

# Tester file
test:			all
	${CC} ${CFLAGS} ${TESTFILE} ${NAME} -o ${TESTFILE:.c=.out}
	@ echo -e "\033[1;36m========-[ Execution output ]-========\033[0;37m"		   > ${LOGFILE}
	-@ exec ${TESTFILE:.c=.out} | cat -e										  >> ${LOGFILE}
	@ echo -e '\n\033[1;35m============-[ Valgrind ]-============\033[0;37m'	  >> ${LOGFILE}
	-@ valgrind ${TESTFILE:.c=.out} --leak-check=full --show-reachable=yes		  >> ${LOGFILE} 2>&1
	@ echo -e "\033[1;32m===========-[ Norm errors ]-==========\033[0;37m"		  >> ${LOGFILE}
	@ norminette ${DIRSRC} | grep "Error" | cat									  >> ${LOGFILE}
	@ echo -e "\033[1;32m======================================\033[0;37m"		  >> ${LOGFILE}
	@ less -R ${LOGFILE}

readlog:
	less -R ${LOGFILE}

# Annnddd Lastly...
clean:
				${RM} ${SRCOBJ} ${BONUSOBJ}
				${RM} vgcore.*

fclean:			clean
				${RM} ${NAME} ${TESTFILE:.c=.out} ${LOGFILE}

re:				fclean all

.PHONY:			all test clean fclean re
