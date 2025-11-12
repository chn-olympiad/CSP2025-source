#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+13;

int t;
int n;
typedef struct AAA
{
    int a,b,c;
    bool operator<(const AAA &d)const
    {
        return min(a-b,a-c)<min(d.a-d.b,d.a-d.c);
    }
}AAA;
AAA A[maxn];
typedef struct BBB
{
    int a,b,c;
    bool operator<(const BBB &d)const
    {
        return min(b-a,b-c)<min(d.b-d.a,d.b-d.c);
    }
}BBB;
BBB B[maxn];
typedef struct CCC
{
    int a,b,c;
    bool operator<(const CCC &d)const
    {
        return min(c-b,c-a)<min(d.c-d.b,d.c-d.a);
    }
}CCC;
CCC C[maxn];


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        long long one=0,two=0,three=0;
        int u=0,v=0,w=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a>b&&a>c)
            {
                one+=a;
                A[++u].a=a;
                A[u].b=b;
                A[u].c=c;
            }
            else if(b>a&&b>c)
            {
                two+=b;
                B[++v].a=a;
                B[v].b=b;
                B[v].c=c;
            }
            else if(c>a&&c>b)
            {
                three+=c;
                C[++w].a=a;
                C[w].b=b;
                C[w].c=c;
            }
            else if(a==b)
            {
                if(u<v)
                {
                    one+=a;
                    A[++u].a=a;
                    A[u].b=b;
                    A[u].c=c;
                }
                else
                {
                    two+=b;
                    B[++v].a=a;
                    B[v].b=b;
                    B[v].c=c;
                }
            }
            else if(a==c)
            {
                if(u<w)
                {
                    one+=a;
                    A[++u].a=a;
                    A[u].b=b;
                    A[u].c=c;
                }
                else
                {
                    three+=c;
                    C[++w].a=a;
                    C[w].b=b;
                    C[w].c=c;
                }
            }
            else if(b==c)
            {
                if(v<w)
                {
                    two+=b;
                    B[++v].a=a;
                    B[v].b=b;
                    B[v].c=c;
                }
                else
                {
                    three+=c;
                    C[++w].a=a;
                    C[w].b=b;
                    C[w].c=c;
                }
            }
            else
            {
                one+=a;
                A[++u].a=a;
                A[u].b=b;
                A[u].c=c;
            }
        }
        int m=(n>>1);
        if(u>m)
        {
            sort(A+1,A+u+1);
            for(int i=1;i<=u-m;++i)
            {
                if(A[i].b>A[i].c)
                {
                    one-=A[i].a;
                    two+=A[i].b;
                }
                else
                {
                    one-=A[i].a;
                    three+=A[i].c;
                }
            }
        }
        else if(v>m)
        {
            sort(B+1,B+v+1);
            for(int i=1;i<=v-m;++i)
            {
                if(B[i].a>B[i].c)
                {
                    two-=B[i].b;
                    one+=B[i].a;
                }
                else
                {
                    two-=B[i].b;
                    three+=B[i].c;
                }
            }
        }
        else if(w>m)
        {
            sort(C+1,C+w+1);
            for(int i=1;i<=w-m;++i)
            {
                if(C[i].a>C[i].b)
                {
                    three-=C[i].c;
                    one+=C[i].a;
                }
                else
                {
                    three-=C[i].c;
                    two+=C[i].b;
                }
            }
        }
        printf("%lld\n",one+two+three);
    }

    return 0;
}

