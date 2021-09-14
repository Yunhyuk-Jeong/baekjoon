//* https://www.acmicpc.net/problem/10866
//* Silver 4

#include <stdio.h>

char input[100] = {
    0,
};
int arr[5000] = {
    0,
};
int start = 2000;
int end = 2001;

void push_front(int i)
{
    arr[start--] = i;
}

void push_back(int i)
{
    arr[end++] = i;
}

int pop_front()
{
    if (arr[start + 1] == 0)
        return -1;
    else
    {
        int r = arr[start + 1];
        arr[++start] = 0;
        return r;
    }
}

int pop_back()
{
    if (arr[end - 1] == 0)
        return -1;
    else
    {
        int r = arr[end - 1];
        arr[--end] = 0;
        return r;
    }
}

int front()
{
    if (arr[start + 1] != 0)
        return arr[start + 1];
    else
        return -1;
}

int back()
{
    if (arr[end - 1] != 0)
        return arr[end - 1];
    else
        return -1;
}

int size()
{
    return end - start - 1;
}

int empty()
{
    if ((end - start - 1) == 0)
        return 1;
    else
        return 0;
}
int main()
{

    int n;

    scanf("%d", &n);

    while (n > 0)
    {
        scanf("%s", &input);

        if (input[1] == 'u' && input[5] == 'f')
        {
            int i;
            scanf("%d", &i);
            push_front(i);
        }
        else if (input[1] == 'u' && input[5] == 'b')
        {
            int i;
            scanf("%d", &i);
            push_back(i);
        }
        else if (input[1] == 'o' && input[4] == 'f')
        {
            printf("%d\n", pop_front());
        }
        else if (input[1] == 'o' && input[4] == 'b')
        {
            printf("%d\n", pop_back());
        }
        else if (input[0] == 's')
        {
            printf("%d\n", size());
        }
        else if (input[0] == 'e')
        {
            printf("%d\n", empty());
        }
        else if (input[0] == 'f')
        {
            printf("%d\n", front());
        }
        else if (input[0] == 'b')
        {
            printf("%d\n", back());
        }

        n--;
    }
    return 0;
}