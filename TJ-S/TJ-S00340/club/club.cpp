//mycode zyc
#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e5+5;
int t,n;
struct node
{
	int a,b,c,big,num;
}s[100005];
bool cmp(node x,node y)
{
	return x.big>y.big;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].big=max(s[i].a,max(s[i].b,s[i].c));
			if(s[i].big==s[i].a) s[i].num=1;
			else if(s[i].big==s[i].b) s[i].num=2;
			else if(s[i].big==s[i].c) s[i].num=3;
		}
		int cnta=0,cntb=0,cntc=0;
		bool opa=1,opb=1,opc=1;
		sort(s,s+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(s[i].num==1&&cnta>=n/2) 
			{
				if(s[i].b>s[i].c||cntc>=n/2) ans+=s[i].b,cntb++;
				else ans+=s[i].c,cntc++;
				continue;
			} 
			else if(s[i].num==2&&cntb>=n/2) 
			{
				if(s[i].a>s[i].c||cntc>=n/2) ans+=s[i].a,cnta++;
				else ans+=s[i].c,cntc++;
				continue;
			}
			else if(s[i].num==3&&cntc>=n/2) 
			{
				if(s[i].b>s[i].a||cnta>=n/2) ans+=s[i].b,cntb++;
				else ans+=s[i].a,cnta++;
			}
			ans+=s[i].big;
			if(s[i].num==1) cnta++;
			else if(s[i].num==2) cntb++;
			else cntc++;
		}
		cout<<ans<<"\n";
	}
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
4 0 0;
*/
