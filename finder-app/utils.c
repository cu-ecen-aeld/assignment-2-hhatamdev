#include "utils.h"

#define UTILS_DBG_BUFF_SIZE (512)
static char utils_log_buff[UTILS_DBG_BUFF_SIZE];

void log_msg(int facility, int level,
             const char *msg,
             const char *file_name,
             const char *function, int line_num)
{
  openlog(NULL, LOG_CONS | LOG_PID, facility);
  syslog(level, "%s, %s, %d: %s ", function, file_name,
         line_num, msg);
  
  closelog();
}

boolean create_path(const char *p_file)
{
  if (NULL != p_file)
  {
    boolean folder_exist = FALSE;
    char *p_folder_name = malloc(strlen(p_file));
    DIR *p_dir = NULL;
    char *pc_folderchar = NULL;
    size_t offset = (size_t)(pc_folderchar - p_file);
    size_t folder_len = offset + 1;
    offset = 0;
    if(p_file[0] == '/')
    {
      /* Make sure not to add a root folder */
      offset = 1;
    }
    while (!folder_exist)
    {
      pc_folderchar = strchr(&p_file[offset], '/');
      if (pc_folderchar != NULL)
      {
        offset = (size_t)(pc_folderchar - p_file);
        folder_len = offset + 1;
        memcpy(p_folder_name, p_file, folder_len - 1);
        p_folder_name[folder_len] = '\0';
        
        p_dir = opendir(p_folder_name);
        if (p_dir == NULL)
        {
          int status;
          
          status = mkdir(p_folder_name, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
          if (status != 0)
          {
            perror("Folder creation Error,");
            snprintf(utils_log_buff, sizeof(utils_log_buff),
                     "Failed to create folder:%s, status:%d\n", p_folder_name, status);
            LOG_MSG(utils_log_buff, LOG_ERR);
            free(p_folder_name);
            return FALSE;
          }
          else
          {
            snprintf(utils_log_buff, sizeof(utils_log_buff),
                     "Created folder %s\n", p_folder_name);
            LOG_MSG(utils_log_buff, LOG_INFO);
          }
        }
        else
        {
          closedir(p_dir);
        }
        ++offset;
      }
      else
      {
        folder_exist = TRUE;
      }
    }
    free(p_folder_name);
  }
  return TRUE;
}
