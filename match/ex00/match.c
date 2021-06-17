/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:19:47 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/07 18:32:32 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		match(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
	{
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	}
	if (*s1 == '\0' && *s2 == '*')
	{
		return (match(s1, s2 + 1));
	}
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		return (match(s1 + 1, s2 + 1));
	}
	if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	return (0);
}


int match(char *s1, char *s2);
 
int main(void)
{
    char *match_a[] = {"Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "Hello World!",
                        "main.c",
                        "Hello World!", 0};
 
    char *match_b[] = {"Hello *",
                        "* World!",
                        "Heww*orld!",
                        "*****ello World****",
                        "Hel*******o******ld!",
                        "Hel* Wo*d!",
                        "He*wo Wo*d!",
                        "**H**e**l**l**o** **W**o**r**l**d**!**",
                        "He*g*lo Wo*r*d*d*!",
                        "*a",
                        "*o",
                        "*!",
                        "*.c",
                        "He*o Workd!", 0};
 
    int i;
 
    i = 0;
    while (match_a[i] != 0)
    {
        while (match_b[i] != 0)
        {
            printf("Do %s and %s match? %d\n", match_a[i], match_b[i], match(match_a[i], match_b[i]));
            i++;;
        }
    }
 
}