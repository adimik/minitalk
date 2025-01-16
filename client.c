/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:03 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/16 00:48:33 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int *atob(char *c)
{
    int i;
    int a;

    i = 0;
    a = malloc(8);    

}

int atoi(char *s)
{
    int i;

    i = 0;
    while(*s != '\0')
    {
        i = i * 10 + (*s - 48); 
        s++;    
    }    
    return(i);
}

int main(int argc,char *argv[])
{
    int i;
    
    i = atoi(argv[1]);
    if(argc != 2)
        return(printf("Incorrect Input"));
    printf("%d", i);
    return(0);
}