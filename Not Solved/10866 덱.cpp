//* https://www.acmicpc.net/problem/10866
//* Silver 4

#include <stdio.h>
#include <string.h>

int deque[10010];
int front = 5001, rear = 5000;

int isEmpty();

void push_front_X(int input)
{
    deque[front++] = input;
}
void push_back_X(int input)
{
    deque[rear--] = input;
}
int pop_front()
{
    if (isEmpty)
        return -1;
    return deque[--front];
}
int pop_back()
{
    if (isEmpty)
        return -1;
    return deque[++rear];
}
int size()
{
    return front - rear - 1;
}
int isEmpty()
{
    return front == rear + 1;
}
int peek_front()
{
    if (isEmpty)
        return -1;
    return deque[front - 1];
}
int peek_back()
{
    if (isEmpty)
        return -1;
    return deque[rear + 1];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char input[100];
        int pushInput;
        scanf("%s", input);
        if (strcmp(input, "push_front"))
        {
            scanf("%d", &pushInput);
            push_front_X(pushInput);
        }
        else if (strcmp(input, "push_back"))
        {
            scanf("%d", &pushInput);
            push_back_X(pushInput);
        }
        else if (strcmp(input, "pop_front"))
            printf("%d", pop_front());
        else if (strcmp(input, "pop_back"))
            printf("%d", pop_back());
        else if (strcmp(input, "size"))
            printf("%d", size());
        else if (strcmp(input, "empty"))
            printf("%d", isEmpty());
        else if (strcmp(input, "front"))
            printf("%d", peek_front());
        else if (strcmp(input, "back"))
            printf("%d", peek_back());
    }
}