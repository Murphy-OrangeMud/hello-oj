#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 100005;
struct node
{
    char name;
    int strnum;
    int child[27];
} trie[maxn * 10];
int nodecnt = 0;
void insert(string s)
{
    node *cur = &trie[0];
    trie[0].strnum++;
    for (int i = 0; i <= s.length(); i++)
    {
        if (i == s.length())
        {
            if (!cur->child[26])
            {
                cur->child[26] = ++nodecnt;
            }
            trie[cur->child[26]].strnum++;
            break;
        }
        if (!cur->child[s[i] - 'A'])
        {
            cur->child[s[i] - 'A'] = ++nodecnt;
        }
        cur = &trie[cur->child[s[i] - 'A']];
        cur->strnum++;
    }
}
int score = 0;
int n = 0, k = 0;
int group(int depth, int curnum)
{
    int remain = 0;
    bool flag = false;
    for (int i = 0; i < 27; i++)
    {
        if (!trie[curnum].child[i])
            continue;
        flag = true;
        if (i == 26)
            remain += group(depth, trie[curnum].child[i]);
        else
            remain += group(depth + 1, trie[curnum].child[i]);
    }
    if (!flag) remain = trie[curnum].strnum;
    score += depth * (remain / k);
    return remain % k;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++)
    {
        memset(trie, 0, sizeof(trie));
        cin >> n >> k;
        string s;
        score = 0;
        nodecnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            insert(s);
        }
        group(0, 0);
        printf("Case #%d: %d\n", tt, score);
    }
    return 0;
}