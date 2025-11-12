#include <bits/stdc++.h>
using namespace std;
const int N=100005;

struct l{
	int di1,di2,di3;
	int cha;
};

l ansa[N/2],ansb[N/2],ansc[N/2],a[N];
bool cmp(l x,l y)
{
	return x.cha>y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int sa=0,sb=0,sc=0,aa=0,bb=0,cc=0;
		long long ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].di1>>a[i].di2>>a[i].di3; 
			if(a[i].di1>=a[i].di2&&a[i].di1>=a[i].di3)
			{
				ansa[++aa]=a[i];
				ansa[aa].cha=min(abs(a[i].di1-a[i].di2),abs(a[i].di1-a[i].di3));
			}
			else if(a[i].di2>=a[i].di1&&a[i].di2>=a[i].di3)
			{
				ansb[++bb]=a[i];
				ansb[bb].cha=min(abs(a[i].di2-a[i].di1),abs(a[i].di2-a[i].di3));
			}
			else
			{
				ansc[++cc]=a[i];
				ansc[cc].cha=min(abs(a[i].di3-a[i].di2),abs(a[i].di3-a[i].di1));
			}
		}
		if(aa>n/2)
		{
			sort(ansa+1,ansa+aa+1,cmp);
			for(int i=n/2+1;i<=aa;i++) ans=ans-ansa[i].cha;
		}
		else if(bb>n/2)
		{
			sort(ansb+1,ansb+bb+1,cmp);
			for(int i=n/2+1;i<=bb;i++) ans=ans-ansb[i].cha;
			
		}
		else if(cc>n/2)
		{
			sort(ansc+1,ansc+cc+1,cmp);
			for(int i=n/2+1;i<=cc;i++) ans=ans-ansc[i].cha;
		}
		for(int i=1;i<=cc;i++) ans=ans+ansc[i].di3;
		for(int i=1;i<=bb;i++) ans=ans+ansb[i].di2;
		for(int i=1;i<=aa;i++) ans=ans+ansa[i].di1;
		cout<<ans<<endl;
	}
	return 0;
 } 
 
 
