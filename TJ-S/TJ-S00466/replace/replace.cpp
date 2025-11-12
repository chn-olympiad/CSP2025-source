#include<bits/stdc++.h>
using namespace std;
int f1[200001],b1[200001],f2[200001],b2[200001],c[200001];
map<int,int> check,find;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin>>a>>b;
	string s1,s2;
	for(int I=0;I<a;I++)
	{
		cin>>s1>>s2;
//		cout<<I;
		for(int J=0;J<s1.length();J++)
		{
			if(s1[J]!='a' && s1[J]!='b')
			{
				cout<<0;
				return 0;
			}
			if(s1[J]=='b')
			{
				f1[I]=J;
				b1[I]=s1.length()-J-1;
				break;
			}
		}
		for(int J=0;J<s2.length();J++)
		{
			if(s2[J]=='b')
			{
				f2[I]=J;
				b2[I]=s2.length()-J-1;
				break;
			}
		}
		c[I]=f2[I]-f1[I];
//		cout<<c[I]<<endl;
	}
	string t1,t2;
	int tf1,k1,tf2,k2,tc;
	for(int I=0;I<b;I++)
	{
		cin>>t1>>t2;
		for(int J=0;J<t1.length();J++)
		{
			if(t1[J]=='b')
			{
				tf1=J;
				k1=t1.length()-J-1;
				break;
			}
		}
		for(int J=0;J<t2.length();J++)
		{
			if(t2[J]=='b')
			{
				tf2=J;
				k2=t2.length()-J-1;
				break;
			}
		}
		tc=tf2-tf1;
		int ans=0;
		for(int J=0;J<a;J++)
		{
			if(c[J]==tc)
			{
				if(f1[J]<=tf1 && b1[J]<=k1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
