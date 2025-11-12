#include<bits/stdc++.h>
using namespace std;
const int N=6e6+10;
struct QAQ{
	int l,r,next;
}a[N];
int h1[N],h2[N],n,m,t;
char x[N],y[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		int len=strlen(x),l,r;
		for(int j=0;j<len;j++) if(x[j]=='b') l=j;
		for(int j=0;j<len;j++) if(y[j]=='b') r=j;
		if(x<y) a[++t].l=l,a[t].r=len-l,a[t].next=h1[r-l],h1[r-l]=t;
		else a[++t].l=l,a[t].r=len-l,a[t].next=h2[l-r],h2[l-r]=t;
	}
	while(m--)
	{
		cin>>x>>y;
		int len=strlen(x),l,r,ans=0;
		for(int i=0;i<len;i++) if(x[i]=='b') l=i;
		for(int i=0;i<len;i++) if(y[i]=='b') r=i;
		if(x<y) for(int i=h1[r-l];i;i=a[i].next) if(l>=a[i].l&&len-l>=a[i].r) ans++;
		else for(int i=h2[l-r];i;i=a[i].next) if(l>=a[i].l&&len-l>=a[i].r) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
