#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct node
{
	string s1,s2;
	int l,b1,b2,db;
}a[N];
bool cmp(node x,node y)
{
	return x.l<y.l;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int hb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		a[i].l=a[i].s1.size();
		if(hb==1)continue;
		a[i].b1=a[i].b2=-1;
		for(int j=0;j<a[i].l;j++)
		{
			if(a[i].s1[j]!='a'||a[i].s1[j]!='b'
			||a[i].s2[j]!='a'||a[i].s2[j]!='b')
			{hb=1;break;}
			if(a[i].s1[j]=='b')a[i].b1=j;
			if(a[i].s2[j]=='b')a[i].b2=j;
		}
		if(a[i].b1==-1||a[i].b2==-1)hb=1;
		a[i].db=a[i].b2-a[i].b1;
	}
	sort(a+1,a+1+n,cmp);
	//for(int i=1;i<=n;i++)cout<<a[i].s1<<" "<<a[i].s2<<" "<<a[i].l<<endl;
	while(q--)
	{
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2)
		{
			puts("0");
			continue;
		}
		if(hb==0)
		{
			int hhb=0,tb1=-1,tb2=-1;
			for(int i=0;i<l1;i++)
			{
				if(t1[i]!='a'||t1[i]!='b'
				||t2[i]!='a'||t2[i]!='b')
				{hhb=1;break;}
				if(t2[i]=='b')tb1=i;
				if(t2[i]=='b')tb2=i;
			}
			if(hhb==0)
			{
				for(int i=1;i<=n;i++)
				{
					if(tb2-tb1==a[i].db&&tb1>=a[i].b1&&
					l1-tb2>=a[i].l-a[i].b2)ans++;
				}
				printf("%d\n",ans);
				continue;
			}
		}
		
		
		int s=0,e=0;
		for(int i=0;i<l1;i++)
			if(t1[i]!=t2[i])
				{s=i;break;}
		for(int i=l1-1;i>=0;i--)
			if(t1[i]!=t2[i])
				{e=i;break;}
		int dl=e-s+1;
		string d1=t1.substr(s,dl),d2=t2.substr(s,dl);
		for(int i=1;i<=n;i++)
		{
			if(a[i].l<dl||a[i].l>l1)continue;
			if(a[i].l==dl)
			{
				if(a[i].s1==d1&&a[i].s2==d2)ans++;
				continue;
			}
			if(a[i].l==l1)
			{
				if(a[i].s1==t1&&a[i].s2==t2)ans++;
				continue;
			}
			for(int j=max(s-(a[i].l-dl),0);j<=s;j++)
			{
				if(t1[j]!=a[i].s1[0]||t2[j]!=a[i].s2[0])
					continue;
				int h=0;
				for(int k=j;k<j+a[i].l;k++)
				{
					if(t1[k]!=a[i].s1[k-j]||
					t2[k]!=a[i].s2[k-j])
					{h=1;break;}
				}
				if(h==0)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 5
ba ab
aba aab
abaa aaab
aaaaaaaaabaa aaaaaaaaaaab
aba aab
*/