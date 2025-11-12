/*
hahahaha , stole sco...
*/
#include <bits/stdc++.h>
using namespace std;

long long qread()
{
    long long res = 0;char ch = getchar();
    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar())
        res = (res << 1) + (res << 3) + ch - '0';
    return res;
}
#define maxn 10004
#define maxm 1000006
#define maxk 10
struct side{int pos1 , pos2;long long wei;};
int pointnum , edgenum , lim;long long res;
side edge[maxm + maxn];int edge_ind = 0;
bool vi[maxn];
long long cost[maxn];
int fapos[maxn + maxm] , si[maxn + maxm];
int st[maxn + maxm] , ind;
int findroot(int pos)
{
    ind = 0;
    for(;fapos[pos] != pos;pos = fapos[pos])st[ind++] = pos;
    for(;ind;)fapos[st[--ind]] = pos;
    return pos;
}
void merge(int pos1 , int pos2)
{
    pos1 = findroot(pos1) , pos2 = findroot(pos2);
    if(pos1 == pos2)return;
    if(si[pos1] < si[pos2])swap(pos1 , pos2);
    fapos[pos2] = pos1;
    si[pos1] += si[pos2];
}
bool cmp(side a , side b){return a.wei < b.wei;}
long long com(int sit)
{
    long long res2 = 0;
    for(int i = 0;i < lim;i++)
        if(sit & (1 << i))res2 += cost[i];
    for(int i = 0;i < pointnum + lim;i++)
        fapos[i] = i , si[i] = 1;
    for(int i = 0;i < pointnum - 1;)
    {
        if((edge[i].pos1 >= pointnum && !((1 << (edge[i].pos1 - pointnum)) & sit)) || 
            (edge[i].pos2 >= pointnum && !((1 << (edge[i].pos2 - pointnum)) & sit)))
            continue;
        if(findroot(edge[i].pos1) != findroot(edge[i].pos2))
        {
            merge(edge[i].pos1 , edge[i].pos2);
            res2 += edge[i].wei;
            i++;
        }
    }
    return res2;
}
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    pointnum = qread();edgenum = qread();lim = qread();
    for(int i = 0;i < edgenum;i++)
    {
        edge[i].pos1 = qread() - 1;edge[i].pos2 = qread() - 1;
        edge[i].wei = qread();
    }
    bool all0 = true;
    for(int i = 0;i < lim;i++)
        for(int j = 0;j < pointnum;j++)
            if(qread()){all0 = false;break;}
    if(all0){puts("0");return 0;}
    for(int i = 0;i < pointnum;i++)
        fapos[i] = i , si[i] = 1;
    sort(edge , edge + edgenum , cmp);
    res = 0;
    for(int i = 0;i < pointnum - 1;)
    {
        if(findroot(edge[i].pos1) != findroot(edge[i].pos2))
        {
            merge(edge[i].pos1 , edge[i].pos2);
            res += edge[i].wei;
            i++;
        }
    }
    // printf("%lld\n" , res);
    // edge_ind = edgenum;
    // for(int i = 0;i < lim;i++)
    // {
    //     cost[i] = qread();
    //     for(int j = 0;j < pointnum;j++)
    //     {
    //         edge[edge_ind].pos1 = pointnum + i , edge[edge_ind].pos2 = j;
    //         edge[edge_ind++].wei = qread();
    //         // printf("ei = %d\n" , edge_ind);
    //         // cerr << edge_ind << '\n';
    //     }
    // }
    // sort(edge , edge + edge_ind , cmp);
    // res = com(0);
    // for(int i = 1;i < (1 << lim);i++)
    //     res = min(res , com(i));
    printf("%lld\n" , res);
    return 0;
}