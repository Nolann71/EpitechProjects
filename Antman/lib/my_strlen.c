/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count number of character in string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
