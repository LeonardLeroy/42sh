/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** display.c
*/

#include "header.h"

// int display_jobs(void *data)
// {
//     jobs_t *job = (jobs_t *)data;

//     mini_printf("[%d] %d ", job->id, job->pid);
//     switch (job->state) {
//         case RUNNING:
//             mini_printf("Running");
//             break;
//         case STOPPED:
//             mini_printf("Stopped");
//             break;
//         case SUSPENDED:
//             mini_printf("Suspended");
//             break;
//         case DONE:
//             mini_printf("Done");
//             break;
//     }
//     for (int i = 0; job->command[i] != NULL; ++i)
//         mini_printf("%s ", job->command[i]);
//     mini_printf("\n");
//     return 0;
// }

int display_jobs(void *data)
{
    mini_printf("[%d] + ", ((jobs_t *)data)->id);
    mini_printf("%d ", ((jobs_t *)data)->pid);
    if (((jobs_t *)data)->state == RUNNING)
        mini_printf("Running", ((jobs_t *)data)->state);
    if (((jobs_t *)data)->state == SUSPENDED)
        mini_printf("Suspended", ((jobs_t *)data)->state);
    if (((jobs_t *)data)->state == TERMINATED)
        mini_printf("Terminated", ((jobs_t *)data)->state);
    if (((jobs_t *)data)->state == DONE)
        mini_printf("Done", ((jobs_t *)data)->state);
    mini_printf("\t\t");
    for (int i = 0; ((jobs_t *)data)->command[i] != NULL; ++i)
        mini_printf("%s ", ((jobs_t *)data)->command[i]);
    mini_printf("\n");
    return 0;
}
