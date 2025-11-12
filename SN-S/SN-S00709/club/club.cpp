#include <bits/stdc++.h>
using namespace std;
struct gg
{
	int n;
	int g;
	int c;
};
int xy(gg x,gg y)
{
	if(x.g<y.g) return 0;
	else return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	gg a[30003];
	cin>>t;
	int q=t;
	int ans[6]={},act=0;
	while(t--)
	{
		int ct[10001]={};int cc[3]={};
//		cout<<"djhfbdhbg"<<act;
		cin>>n;
		int ip=n*3;
		for(int i=0;i<n;i++)
		{
//			cin>>a[i].g>>a[i+1].g>>a[i+2].g;
//			a[i].n=i/3;a[i+1].n=i/3+1;a[i].n=i/3;
//			a[i].c=i%3;
			for(int j=0;j<3;j++)
			{
				cin>>a[i*3+j].g;
				a[i*3+j].n=i;
				a[i*3+j].c=j;
//				cout<<" k "<<a[i*3+j].c<<a[i*3+j].n<<a[i*3+j].g<<endl;
//				cout<<'l';
			}
		}
//		sort(a,a+n,xy);sort(b,b+n,xy);sort(c,c+n,xy);
		sort(a,a+ip,xy);
//		for(int i=0;i<n*3;i++)
//		{
//			cout<<a[i].g<<' ';
//		}
//		cout<<"  uu  "<<a[0].g<<a[0].c<<a[0].n;
		for(int i=0;i<ip;i++)
		{
			//if sth happens illfrankyou
			if(ct[a[i].n]) continue;
			if(cc[a[i].c]>=n/2) continue;
			//making answwerwerwer
			ans[act]+=a[i].g;
//			cout<<a[i].g<<'l';
			cc[a[i].c]++;
			ct[a[i].n]=1;
		}
//		cout<<ans[act]<<endl;
		act++;
	}
//	cout<<endl<<ans[1]<<ans[2]<<endl;
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
