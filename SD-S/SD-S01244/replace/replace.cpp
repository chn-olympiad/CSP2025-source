//replace
#include<iostream>
#include<cstdio>
#define endl '\n'
using namespace std;
typedef unsigned long long ull;
int const N=2e5+10,P=31;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	string t1,t2,tmp;
	if(n<=100)
	{
		while(q--)
		{
			int ans=0;
			cin>>t1>>t2;
			if(t1.size()!=t2.size())
			{
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				tmp=t1;
	//			cout<<i<<' '<<s1[i]<<' '<<s2[i]<<' '<<t1<<' '<<t2<<endl;
				int x=tmp.find(s1[i]);
				if(x==-1) continue;
				tmp.replace(x,s1[i].size(),s2[i]);
	//			cout<<' '<<i<<' '<<s1[i]<<' '<<s2[i]<<' '<<tmp<<endl;
				if(t2==tmp) ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
		cout<<0<<endl;
	return 0;
 }
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*//*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
