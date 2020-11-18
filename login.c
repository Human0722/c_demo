//
// Created by Human0722 on 2020/11/18.
//
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int c;
    char *username = NULL;
    char *passwd = NULL;
    char *action = NULL;

    while((c = getopt(argc, argv, "a:u:p:")) != -1)
    {
        switch(c)
        {
            case 'a':
                action = optarg;
                break;
            case 'u':
                username = optarg;
                break;
            case 'p':
                passwd = optarg;
                break;
            case '?':
                if(optopt == 'a' || optopt == 'u' || optopt == 'p')
                {
                    fprintf(stderr, "Option -%c needs argument!", optopt);
                } else
                {

                    fprintf(stderr, "Unknown option -%c.", optopt);
                }
            default:
                perror("Error!");
        }
    }
    printf("Welcome!\n");
    printf("Username: %s\n", username);
    printf("Passwd: %s\n", passwd);
}

