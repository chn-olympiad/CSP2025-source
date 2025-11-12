#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct p{
 int a,b,c,f;
}s[N];
bool cmpa(p x,p y)
{
    return x.a>y.a;
}
bool cmpb(p x,p y)
{
    return x.b>y.b;
}
bool cmpc(p x,p y)
{
    return x.c>y.c;
}
long long n,ans=0,mx=0,t,js=0;
void aaa()
{
	sort(s+1,s+n+1,cmpa);
	for(int i=1;i<=n;i++)
    {
        if(s[i].f!=1)
        {
            ans+=s[i].a;
            s[i].f=1;
            js++;
            if(js>=n/2)break;
        }
    }
    js=0;
}
void bbb()
{
	sort(s+1,s+n+1,cmpb);
    for(int i=1;i<=n;i++)
    {
        if(s[i].f!=1)
        {
            ans+=s[i].b;
            s[i].f=1;
            js++;
            if(js>=n/2)break;
        }

    }
    js=0;
}
void ccc()
{
	sort(s+1,s+n+1,cmpc);
    for(int i=1;i<=n;i++)
    {
        if(s[i].f!=1)
        {
            ans+=s[i].c;
            s[i].f=1;
            js++;
            if(js>=n/2)break;
        }

    }
    js=0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].a>>s[i].b>>s[i].c;
            s[i].f=0;
        }
        aaa();
        bbb();
        ccc();
        mx=max(ans,mx);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            s[i].f=0;
        }
        aaa();
        ccc();
        bbb();
        mx=max(ans,mx);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            s[i].f=0;
        }
		bbb();
       	aaa();
        ccc();
        mx=max(ans,mx);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            s[i].f=0;
        }
		bbb();
		ccc();
        aaa();
        mx=max(ans,mx);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            s[i].f=0;
        }
        ccc();
		bbb();
        aaa();
        mx=max(ans,mx);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            s[i].f=0;
        }
        ccc();
		aaa();
        bbb();
        mx=max(ans,mx);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            s[i].f=0;
        }
        cout<<mx<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
