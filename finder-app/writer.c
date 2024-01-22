#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "utils.h"

#define WRITER_DBG_BUFF_SIZE (512)
static char writer_log_buff[WRITER_DBG_BUFF_SIZE];

int main(int argc, char *argv[])
{
  FILE * p_this_file = NULL;
  
  if (argc != 3)
  {
    snprintf(writer_log_buff, sizeof(writer_log_buff), 
             "Invalid number of arguments\n");
    
    LOG_MSG(writer_log_buff, LOG_ERR);
    printf("%s", writer_log_buff);

    printf("Usage: %s writefile writestr \n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if(!create_path(argv[1]))
  {
    snprintf(writer_log_buff, sizeof(writer_log_buff),
             "Failed to create folders for file:%s\n", argv[1]);
    LOG_MSG(writer_log_buff, LOG_ERR);
    exit(EXIT_FAILURE);
  }

  snprintf(writer_log_buff, sizeof(writer_log_buff),
           "Writing \"%s\" to %s\n",
           argv[2], argv[1]);
  LOG_MSG(writer_log_buff, LOG_DEBUG);

  p_this_file = fopen(argv[1], "w");
  if (NULL == p_this_file)
  {
    snprintf(writer_log_buff, sizeof(writer_log_buff),
             "Failed to open file:%s\n", argv[1]);
    LOG_MSG(writer_log_buff, LOG_ERR);
    exit(EXIT_FAILURE);
  }
  else if (fprintf(p_this_file, "%s\n", argv[2]) < 0)
  {
    int this_err = errno;
    snprintf(writer_log_buff, sizeof(writer_log_buff),
             "Error %s, Failed to write \"%s\" to file %s\n",
             strerror(this_err), argv[2], argv[1]);
    LOG_MSG(writer_log_buff, LOG_ERR);
    exit(EXIT_FAILURE);
  }
  fclose(p_this_file);

  exit(EXIT_SUCCESS);
}

