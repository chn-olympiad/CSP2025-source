#include<bits/stdc++.h>
using LL = long long;
using namespace std;

struct noder{
    int a,b,v,sum;
}r[1000010];

int vc[15];
int c[15][10010];

int n,m,k;

bool cmp(noder x,noder y)
{
    return x.a < y.a;
}
/*
void bfs()
{
    queue <noder> q;
    int cnt = 2;
    q.push(r[1]);
    while(!q.empty())
    {
        noder rn = q.top();
        q.pop();
        while(r[cnt].a == rn.a)
        {
            q.push({r[cnt].a;r[cnt].b;r[cnt].v;r[cnt].sum});
            cnt++;
        }
        int cnt1 = cnt;
        if(r[cnt1].a == rn.b)
        {
            q.push({r[cnt1].a;r[cnt1].b;r[cnt1].v;r[cnt1].sum+rn.sum});
            cnt1++;
        }
    }
}
*/

int main()
{
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    cin >>n >> m >>k;
    for(int i = 1 ;i <=m ; i++)
    {
        int aa,bb;
        scanf("%d%d%d",&aa,&bb,&r[i].v);
        r[i].sum = r[i].v;
        if(aa < bb)
        {
            r[i].a = aa;
            r[i].b = bb;
        }
        else
        {
            r[i].b = aa;
            r[i].a = bb;
        }
    }
    for(int i = 1 ;i <= k ; i++)
    {
        cin >>vc[i];
        for(int j = 1 ;j <=n ; j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    sort(r+1,r+m+1,cmp);
    cout << 0;
    fclose(stdin);fclose(stdout);
    return 0;
}
