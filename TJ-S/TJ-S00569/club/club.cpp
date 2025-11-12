#include<bits/stdc++.h>
using LL = long long;
using namespace std;

struct node
{
    int a,b,c,wh1,d;
    bool u = 0;
}m[100010];
int T;


bool cmp1(node x,node y)
{

    return x.d > y.d;
}
bool cmp2(node x,node y)
{
    return x.d > y.d;
}
bool cmp3(node x,node y)
{
    return x.d > y.d;
}

int main()
{
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int cntw1=0,cntw2=0,cntw3=0,id = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d %d %d",&m[i].a,&m[i].b,&m[i].c);
            m[i].u = 0;
            if(m[i].a > m[i].b)
                if(m[i].c > m[i].a)
                {
                    m[i].wh1 = 3;
                    cntw3++;
                    m[i].d = m[i].c-m[i].a;
                }
                else
                {
                    m[i].wh1 = 1;
                    cntw1++;
                    if(m[i].b > m[i].c) m[i].d = m[i].a-m[i].b;
                    else m[i].d = m[i].a-m[i].c;
                }
            else
                if(m[i].c > m[i].b)
                {
                    m[i].wh1 = 3;
                    cntw3++;
                    m[i].d = m[i].c-m[i].b;
                }
                else
                {
                    m[i].wh1 = 2;
                    cntw2++;
                    if(m[i].a > m[i].c) m[i].d = m[i].b-m[i].a;
                    else m[i].d = m[i].b-m[i].c;
                }
        }
        if(cntw1 > cntw2)
            if(cntw3 > cntw1) id = 3;
            else id = 1;
        else
            if(cntw3 > cntw2) id = 3;
            else id = 2;
        int cnt1 = 0,cnt2 = 0,cnt3 = 0,hn = n/2,sum = 0;
        if(id == 1)
        {
            sort(m+1,m+n+1,cmp1);
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt1 == hn) break;
                if(m[i].wh1 == 1)
                {
                    if(m[i].u == 0){
                        sum += m[i].a;
                        m[i].u = 1;
                        cnt1++;
                    }
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt2 == hn) break;
                if(m[i].u == 0 && m[i].b > m[i].c){
                    sum += m[i].b;
                    m[i].u = 1;
                    cnt2++;
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt3 == hn) break;
                if(m[i].u == 0){
                    sum += m[i].c;
                    m[i].u = 1;
                    cnt3++;
                }
            }
        }
        else if(id == 2)
        {
            sort(m+1,m+n+1,cmp2);
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt2 == hn) break;
                if(m[i].wh1 == 2)
                {
                    if(m[i].u == 0){
                        sum += m[i].b;
                        m[i].u = 1;
                        cnt2++;
                    }
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt1 == hn) break;
                if(m[i].u == 0 && m[i].a > m[i].c){
                    sum += m[i].a;
                    m[i].u = 1;
                    cnt1++;
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt3 == hn) break;
                if(m[i].u == 0){
                    sum += m[i].c;
                    m[i].u = 1;
                    cnt3++;
                }
            }
        }
        else
        {
            sort(m+1,m+n+1,cmp3);
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt3 == hn) break;
                if(m[i].wh1 == 3)
                {
                    if(m[i].u == 0){
                        sum += m[i].c;
                        m[i].u = 1;
                        cnt3++;
                    }
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt2 == hn) break;
                if(m[i].u == 0 && m[i].b > m[i].a){
                    sum += m[i].b;
                    m[i].u = 1;
                    cnt2++;
                }
            }
            for(int i = 1 ; i <= n ; i++)
            {
                if(cnt1 == hn) break;
                if(m[i].u == 0){
                    sum += m[i].a;
                    m[i].u = 1;
                    cnt1++;
                }
            }
        }
        cout << sum << endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
