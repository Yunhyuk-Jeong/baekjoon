//* https://www.acmicpc.net/problem/10814
//* Silver 5

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct oj
{
    int age;
    char name[102];
} oj;

int n = 0;

oj person[100001];

int main(void)
{
    int min_age = 1000, max_age = -1000;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &person[i].age, person[i].name);

        if (min_age > person[i].age)
            min_age = person[i].age;

        if (max_age < person[i].age)
            max_age = person[i].age;
    }

    for (int i = min_age; i <= max_age; i++)
        for (int j = 0; j < n; j++)
            if (person[j].age == i)
                printf("%d %s\n", person[j].age, person[j].name);

    return 0;
}