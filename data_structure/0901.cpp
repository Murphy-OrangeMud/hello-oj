// WA: 注意第一个顺串的尺寸一定小于等于堆的尺寸（min(m,n)）
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cstdio>
using namespace std;
void sift_down(int cur, int tail, int *heap)
{
    while (2 * cur + 1 < tail && 2 * cur + 2 < tail)
    {
        if (heap[cur] < heap[2 * cur + 1] && heap[cur] < heap[2 * cur + 2])
        {
            break;
        }
        if (heap[2 * cur + 1] < heap[2 * cur + 2])
        {
            int temp = heap[2 * cur + 1];
            heap[2 * cur + 1] = heap[cur];
            heap[cur] = temp;
            cur = 2 * cur + 1;
            continue;
        }
        else
        {
            int temp = heap[2 * cur + 2];
            heap[2 * cur + 2] = heap[cur];
            heap[cur] = temp;
            cur = 2 * cur + 2;
        }
    }
    while (2 * cur + 1 < tail)
    {
        if (heap[cur] < heap[2 * cur + 1])
            break;
        int temp = heap[2 * cur + 1];
        heap[2 * cur + 1] = heap[cur];
        heap[cur] = temp;
        cur = 2 * cur + 1;
    }
}
void push_heap(int *heap, int size) {
    for (int i = size/2; i >= 0; i--) {
        sift_down(i, size, heap);
    }
}
int m, n;
int main()
{
    scanf("%d%d", &m, &n);
    int *seq = (int *)malloc(m * sizeof(int));
    int *heap = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d", seq + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", heap + i);
    }
    int tail = n;
    for (int i = 0; i < min(m, n); i++)
    {
        if (i)
            printf(" ");
        printf("%d", heap[0]);
        if (tail != 1) {
            heap[0] = heap[--tail];
            heap[tail] = seq[i];
            sift_down(0, tail, heap);
        }
        else {
            heap[0] = seq[i];
            push_heap(heap, n);
            tail = n;
        }
    }
    return 0;
}