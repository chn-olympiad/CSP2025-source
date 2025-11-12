#include <bits/stdc++.h>
using namespace std;

int n,t,m;
//struct node;
//{
//	int a1;
//	int a2;
//	int a3;
//}

int a1[100010];
int a2[100010];
int a3[100010];
//node a[100010];
long long ans,ans1;

bool com(int a,int b)
{
	return a>b;
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	for(;t--;)
	{
		cin>>n;
		
		if(n==2)
		{
			int b1[5],b2[5];
			cin>>b1[1]>>b1[2]>>b1[3];
			cin>>b2[1]>>b2[2]>>b2[3];
			int temp1=max({b1[1],b1[2],b1[3]});
			int temp2=max({b2[1],b2[2],b2[3]});
			int p1=find(b1+1,b1+4,temp1)-b1;
			int p2=find(b2+1,b2+4,temp2)-b2;
			if(p1!=p2) cout<<temp1+temp2<<"\n";
			else
			{
				int maxn1=b1[p1],maxn2=b2[p2];
				b1[p1]=-1,b2[p2]=-1;
				int temp3=max({b1[1],b1[2],b1[3]});
				int temp4=max({b2[1],b2[2],b2[3]});
				if((temp1-temp3)>(temp2-temp4))
				{
					cout<<temp1+temp4<<"\n";
				}
				else if((temp1-temp3)<=(temp2-temp4))
				{
					cout<<temp2+temp3<<"\n";
				}
			}
			continue;
		}
		
		bool f1=true,f2=true;
		for(int i=1;i<=n;++i)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
//			cin>>a.a1>>a.a2>>a.a3;
			if(a2[i]!=0) f1=false;
			if(a3[i!=0]) f2=false;
			ans+=max({a1[i],a2[i],a3[i]});
		}
		if(f1&&f2)
		{
			sort(a1+1,a1+n+1,com);
			for(int i=1;i<=n/2;++i)
				ans1+=a1[i];
			cout<<ans1<<"\n";
		}
//		else if(f2)
//		{
//			
//		}
		else
		{
			cout<<ans<<"\n";
		}
		ans=ans1=0;
	}
	
	return 0;
} 
