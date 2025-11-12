#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
string s1[N],s2[N],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int k=0;
			while(t1.find(s1[i],k)!=string::npos)
			{
				k=t1.find(s1[i],k)+1;
				string a=t1.substr(0,k-1),b=t1.substr(k-1+s1[i].size());
//				cout<<k<<" "<<a<<" "<<b<<" ";
				if(a+s2[i]+b==t2)
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
