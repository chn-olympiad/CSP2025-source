#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int T;
int n;
struct stu
{
	int a,b,c;
	int typ;
	int xc;
};
stu s[100005];
int check[5];
int ans=0;
bool cmpb(stu x,stu y)
{
	return x.xc>y.xc;
}
bool cmp(stu x,stu y)
{
	return x.xc>y.xc;
}
int soa()
{
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i].b-s[i].a>s[i].c-s[i].a)
		{
			s[i].xc=s[i].b-s[i].a;
			s[i].typ=2;
		}
		else
		{
			s[i].xc=s[i].c-s[i].a;
			s[i].typ=3;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		tot+=s[i].a;
	}
	for(int i=1;i<=n/2;i++)
	{
		tot+=s[i].xc;
		check[s[i].typ]++;
	}
	int pos=n/2+1;
	while(s[pos].xc>=0&&check[1]<n/2&&check[2]<n/2&&check[3]<n/2)
	{
		check[s[pos].typ]++;
		tot+=s[pos].xc;
		pos++;
	}
	check[1]=0;
	check[2]=0;
	check[3]=0;
	return tot;
}
int sob()
{
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i].a-s[i].b>s[i].c-s[i].b)
		{
			s[i].xc=s[i].a-s[i].b;
			s[i].typ=1;
		}
		else
		{
			s[i].xc=s[i].c-s[i].b;
			s[i].typ=3;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		tot+=s[i].b;
	}
	for(int i=1;i<=n/2;i++)
	{
		tot+=s[i].xc;
		check[s[i].typ]++;
	}
	int pos=n/2+1;
	while(s[pos].xc>=0&&check[1]<n/2&&check[2]<n/2&&check[3]<n/2)
	{
		check[s[pos].typ]++;
		tot+=s[pos].xc;
		pos++;
	}
	check[1]=0;
	check[2]=0;
	check[3]=0;
	return tot;
}
int soc()
{
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i].a-s[i].c>s[i].b-s[i].c)
		{
			s[i].xc=s[i].a-s[i].c;
			s[i].typ=1;
		}
		else
		{
			s[i].xc=s[i].b-s[i].c;
			s[i].typ=2;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		tot+=s[i].c;
	}
	for(int i=1;i<=n/2;i++)
	{
		tot+=s[i].xc;
		check[s[i].typ]++;
	}
	int pos=n/2+1;
	while(s[pos].xc>=0&&check[1]<n/2&&check[2]<n/2&&check[3]<n/2)
	{
		check[s[pos].typ]++;
		tot+=s[pos].xc;
		pos++;
	}
	check[1]=0;
	check[2]=0;
	check[3]=0;
	return tot;
}
void solveak()
{
	ans=max(soa(),ans);
	ans=max(sob(),ans);
	ans=max(ans,soc());
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		solveak();
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			s[i].a=0;
			s[i].b=0;
			s[i].c=0;
			s[i].typ=0;
			s[i].xc=0;
		}
		check[1]=0;
		check[2]=0;
		check[3]=0;
		ans=0;
	}
	cout<<endl;
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
