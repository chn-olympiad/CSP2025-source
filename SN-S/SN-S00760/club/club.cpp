#include<bits/stdc++.h>
#define int long long
using namespace std;
struct stu
{
	int t1,t2,t3,mx,cmx,mi,c1,c2,num; //c1:max-cmax
} a[1010101];
bool cmp(stu x,stu y)
{
	if(x.c1!=y.c1) return x.c1>y.c1;
	else return x.c2>y.c2;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int ans=0,cnt1=0,cnt2=0,cnt3=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].t1>>a[i].t2>>a[i].t3;
			a[i].mx=max({a[i].t1,a[i].t2,a[i].t3});
			if(a[i].mx==a[i].t1) a[i].num=1,cnt1++;
			else if(a[i].mx==a[i].t2) a[i].num=2,cnt2++;
			else a[i].num=3,cnt3++;
			if(a[i].mx==a[i].t1) a[i].cmx=max(a[i].t2,a[i].t3);
			if(a[i].mx==a[i].t2) a[i].cmx=max(a[i].t1,a[i].t3);
			if(a[i].mx==a[i].t3) a[i].cmx=max(a[i].t2,a[i].t1);
			ans+=a[i].mx;
		}	
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) 
		{
			cout<<ans<<endl;
			continue;
		}
		int cnum=0,tnum=0;
		if(cnt1>n/2) cnum=1,tnum=cnt1-n/2;
		if(cnt2>n/2) cnum=2,tnum=cnt2-n/2;
		if(cnt3>n/2) cnum=3,tnum=cnt3-n/2;
		vector<int> cb;
		for(int i=1;i<=n;i++)
		{
			if(a[i].num==cnum) cb.push_back(a[i].mx-a[i].cmx);
		}
		sort(cb.begin(),cb.end());
		for(int i=0;i<cb.size()&&tnum>0;i++)
		{
			ans-=cb[i];
			tnum--;
		}
		cout<<ans<<endl;
 	}
	return 0;
}
/*
if(n>400)
		{
			int sum3=0;
			for(int i=1;i<=n;i++) 
			{
				cin>>a[i].t1>>a[i].t2>>a[i].t3;
				sum3+=a[i].t3;
				a[i].mx=max({a[i].t1,a[i].t2,a[i].t3});
				if(a[i].mx==a[i].t1) a[i].cmx=max(a[i].t2,a[i].t3);
				if(a[i].mx==a[i].t2) a[i].cmx=max(a[i].t1,a[i].t3);
				if(a[i].mx==a[i].t3) a[i].cmx=max(a[i].t2,a[i].t1);
				a[i].mi=min({a[i].t1,a[i].t2,a[i].t3});
				a[i].c1=a[i].t1-a[i].t2;
			}		
			if(sum3==0)
			{
				sort(a+1,a+n+1,cmp);
				int ans=0;
				for(int i=1;i<=n/2;i++) ans+=a[i].t1;
				for(int i=n/2+1;i<=n;i++) ans+=a[i].t2;
				cout<<ans<<endl;
			}
			else
			{
				int ans=0;
				for(int i=1;i<=n;i++) ans+=a[i].mx;
				cou<<ans<<endl; 
			}
		}

*/
