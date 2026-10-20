#include <stdio.h>
#include <time.h>

void game_log(const char *log_type, const char *log_messages)
{
    FILE *file = fopen("game.log", "a");

    if (file == NULL)
    {
        perror("fopen: ");
        return;
    }

    time_t now = time(NULL);

    struct tm *time_info = localtime(&now);

    if (time_info != NULL)
    {
        fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] ", 
                time_info->tm_year + 1900,
                time_info->tm_mon + 1,
                time_info->tm_mday,
                time_info->tm_hour,
                time_info->tm_min,
                time_info->tm_sec);
    }

    fprintf(file, "[%s] %s", log_type, log_messages);

    if (fclose(file) == EOF)
    {
        perror("fclose: ");
    }
}

int main(void)
{

    game_log("ERROR", "Invalid input.");

    return 0;
}