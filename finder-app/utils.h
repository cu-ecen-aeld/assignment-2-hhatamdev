#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <syslog.h>

#define FALSE 0
#define TRUE 1

typedef unsigned int boolean;



#define LOG_MSG(msg, level) log_msg(LOG_USER, (level), (msg), __FILE__, __FUNCTION__, __LINE__)

void log_msg(int facility, int level,
             const char *msg,
             const char *file_name,
             const char *function, int line_num);

boolean create_path(const char *p_file);

#endif /* __UTILS_H__*/