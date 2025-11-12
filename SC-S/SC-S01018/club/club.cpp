#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans=0;
struct P{
	int a,b,c;
}p[N];
bool cmp(P x,P y)
{
	if(x.a-x.b!=y.a-y.b) return x.a-x.b>y.a-y.b;
	else return x.a>y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
		sort(p+1,p+1+n,cmp);
		int i=1,j=n/2+1;
		while(i<=n/2)
		{
			ans+=p[i].a;
			i++;
		}
		while(j<=n)
		{
			ans+=p[j].b;
			j++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}