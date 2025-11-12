#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
};
stu d[100005];

int n,ans;
int mx,my;
int T,c_1,c_2,c_3;


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	for(int I=1;I<=T;I++)
	{
		cin>>n;
		ans=0;
		my=0;
		mx=0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i].a>>d[i].b>>d[i].c;
			mx=max(d[i].a,d[i].b);
			mx=max(mx,d[i].c);
			ans+=mx;
		}
		
		cout<<ans;
	}
return 0;
}
