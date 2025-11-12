#include<bits/stdc++.h>
using namespace std;
struct A
{
	int a1,a2,a3;
	bool operator<(const A x)const{
		int m1,m2,m3,m4;
		m1=max(a1,max(a2,a3));
		m2=max(x.a1,max(x.a2,x.a3));
		m3=min(a1,min(a2,a3));
		m4=min(x.a1,min(x.a2,x.a3));
		return ((2*m1-a1-a2-a3)==(2*m2-x.a1-x.a2-x.a3)?(a1+a2+a3-m1-2*m3)>=(x.a1+x.a2+x.a3-m2-2*m4):(2*m1-a1-a2-a3)>(2*m2-x.a1-x.a2-x.a3));
	}
}a[100005];
int f(A x,int m)
{
	if(m==x.a1)return 1;
	if(m==x.a2)return 2;
	if(m==x.a3)return 3;
}
int t,n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1);
		int y[4]={0},ans=0;
		A x;
    	for(int i=1;i<=n;i++)
    	{
    		x=a[i];
			int m1,m2,m3;
			m1=max(x.a1,max(x.a2,x.a3));
			m2=x.a1+x.a2+x.a3-m1-min(x.a1,min(x.a2,x.a3));
			if(y[f(x,m1)]<(n/2.0))y[f(x,m1)]++,ans+=m1;
			else y[f(x,m2)]++,ans+=m2;
		}
		cout<<ans<<endl;
	}
    return 0;
}
