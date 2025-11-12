#include<bits/stdc++.h>
using namespace std;
int t,n,cnta,cntb,cntc,ans,vis[100005];
struct node
{
	int group,value;
} a[100005],b[100005],c[100005];
bool cmp(node a,node b)
{
	if(a.value>b.value) return true;
	else return false;
}
bool ada()
{
	while(vis[a[cnta].group]) cnta++;
	if(cnta>n/2) return false;
	vis[a[cnta].group]=1;
	ans+=a[cnta].value;
	return true;
}
bool adb()
{
	while(vis[b[cntb].group]) cntb++;
	if(cntb>n/2) return false;
	vis[b[cntb].group]=1;
	ans+=b[cntb].value;
	return true;
}
bool adc()
{
	while(vis[c[cntc].group]) cntc++;
	if(cntc>n/2) return false;
	vis[c[cntc].group]=1;
	ans+=c[cntc].value;
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnta=1,cntb=1,cntc=1,ans=0;
		for(int i=1; i<=n; i++)
		{
			vis[i]=0;
			scanf("%d%d%d",&a[i].value,&b[i].value,&c[i].value);
			a[i].group=i;
			b[i].group=i;
			c[i].group=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1; i<=n; i++)
		{
			if(a[cnta].value>=b[cntb].value && a[cnta].value>=c[cntc].value)
			{
				if(ada()) continue;
				if(c[cntc].value>=b[cntb].value && adc()) continue;
				if(adb()) continue;
			}
			if(b[cntb].value>=a[cnta].value && b[cntb].value>=c[cntc].value)
			{
				if(adb()) continue;
				if(a[cnta].value>=c[cntc].value && ada()) continue;
				if(adc()) continue;
			}
			if(c[cntc].value>=b[cntb].value && c[cntc].value>=a[cnta].value)
			{
				if(adc()) continue;
				if(a[cnta].value>=b[cntb].value && ada()) continue;
				if(adb()) continue;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}