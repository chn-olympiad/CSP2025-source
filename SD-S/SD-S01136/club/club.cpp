#include<bits/stdc++.h>
using namespace std;

struct node{
	int id,v;
};

bool cmp(node aa,node ba)
{
	return aa.v<ba.v;
}

int a[100005][5];
int num[5];
node ch[100005];
void solve()
{
	for(int i=0;i<=100004;i++) 
		for(int j=0;j<=4;j++)
			a[i][j]=0,ch[i].v=ch[i].id=0;
	for(int i=0;i<=4;i++) num[i]=0; 
	int ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
		int onee=a[i][1],twoo=a[i][2],thrr=a[i][3];
		if(onee<twoo) swap(onee,twoo);
		if(onee<thrr) swap(onee,thrr);
		if(twoo<thrr) swap(twoo,thrr);
		ch[i].v=onee-twoo;
	}
	for(int i=1;i<=n;i++)
	{
		int onee=a[i][1],twoo=a[i][2],thrr=a[i][3],onn=1,tww=2,thh=3;
		if(onee<twoo) swap(onee,twoo),swap(onn,tww);
		if(onee<thrr) swap(onee,thrr),swap(onn,thh);
		if(twoo<thrr) swap(twoo,thrr),swap(tww,thh); 
		ans+=onee;
		num[onn]++;
		ch[i].id=onn;
	}
	if(max(max(num[1],num[2]),num[3])<=n/2)
	{
		cout<<ans<<'\n';
	}
	else
	{
		int cn;
		if(num[1]>num[2]&&num[1]>num[3]) cn=1;
		else if(num[2]>num[1]&&num[2]>num[3]) cn=2;
		else cn=3;
		sort(ch+1,ch+n+1,cmp);
		int i=1;
		while(num[cn]>n/2)
		{
			if(ch[i].id==cn)
			{
				ans-=ch[i].v;
				num[cn]--;
			}
			i++;
		}
		cout<<ans<<endl;
	}
}

int main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
//Ren5Jie4Di4Ling5%
