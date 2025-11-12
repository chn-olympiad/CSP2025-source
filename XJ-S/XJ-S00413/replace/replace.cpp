#include<iostream>
#include<cstring>
using namespace std;
int n,q;
char x[5000005],y[5000005];
struct node{
	int lenx,xb;
}ax[200005];
struct nod{
	int leny,yb;
}ay[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		int l=strlen(x);
		ax[i].lenx=l;
		while(l--)
		{
			if(x[l]=='b')
			{
				ax[i].xb=l;
				break;
			}
		}
		l=strlen(x);
		ay[i].leny=l;
		while(l--)
		{
			if(y[l]=='b')
			{
				ay[i].yb=l;
				break;
			}
		}
//		cout<<ax[i].xb<<" "<<ay[i].yb<<endl;
	}
	int ans;
	for(int i=1;i<=q;i++)
	{
		ans=0;
		int mm,nn;
		cin>>x>>y;
		int l1=strlen(x),l2=strlen(y);
		int f1=0,f2=0;
		for(int j=0;j<=n;j++)
		{
			if(x[j]=='b')
			{
				f1=1;
				mm=j;
			}
			if(y[j]=='b')
			{
				f2=1;
				nn=j;
			}
			if(f1&&f2)
			{
				break;
			}
		}
//		cout<<mm<<" "<<nn<<endl;
		for(int j=1;j<=n;j++)
		{
			if(mm+(ay[j].yb-ax[j].xb)==nn&&mm-ax[j].xb>=0&&nn-ay[j].yb>=0&&mm+(ax[j].lenx-ax[j].xb)<=l1&&nn+(ay[j].leny-ay[j].yb)<=l2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
