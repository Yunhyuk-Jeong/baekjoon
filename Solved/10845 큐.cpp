//* https://www.acmicpc.net/problem/10845
//* Silver 4

#include <stdio.h>
#include <string.h>

int queue[10010];
int front = 0, rear = 0;

int isEmpty();

void push()
{
    rear += 1;
    scanf("%d", &queue[rear]);
}

int pop()
{
    if (isEmpty() == true)
        return -1;
    front += 1;
    return queue[front];
}

int size()
{
    return rear - front;
}

int isEmpty()
{
    return rear == front;
}

int front_peek()
{
    return rear == front ? -1 : queue[front + 1];
}
int back_peek()
{
    return rear == front ? -1 : queue[rear];
}

int main()
{
    int n;
    char data[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", data);
        if (strcmp(data, "push") == 0)
            push();

        else if (strcmp(data, "pop") == 0)
            printf("%d\n", pop());

        else if (strcmp(data, "size") == 0)
            printf("%d\n", size());

        else if (strcmp(data, "empty") == 0)
            printf("%d\n", isEmpty());

        else if (strcmp(data, "front") == 0)
            printf("%d\n", front_peek());

        else if (strcmp(data, "back") == 0)
            printf("%d\n", back_peek());
    }
    return 0;
}