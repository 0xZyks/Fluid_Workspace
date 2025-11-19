#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int		fl_strlen(char *s);
int		fl_strcmp(char *s1, char *s2);
char	*fl_strjoin(char *s1, char *s2);
char	*fl_strjoin_sep(char *s1, char *s2, char *sep);
char	*get_env(void);

#endif
