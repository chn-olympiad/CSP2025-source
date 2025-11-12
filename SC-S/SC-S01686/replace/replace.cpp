#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
struct Stu
{
	string s1,s2;
}g[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i].s1>>g[i].s2;
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<t1.size()-g[i].s1.size()+1;j++)
			{
				string t=t1.substr(j,g[i].s1.size());
				if(t!=g[i].s1) continue;
				string s;
				for(int k=0;k<t1.size();k++)
				{
					if(k<j||k>j+g[i].s2.size()-1) s+=t1[k];
					else
					{
//						cout<<"g[i].s2[k-j]="<<g[i].s2[k-j]<<endl;
						s+=g[i].s2[k-j];
					}
//					cout<<s<<" k="<<k<<" j="<<j<<" g[i].s2.size()="<<g[i].s2.size()<<" t[k-j]="<<t[k-j]<<" g[i].s2[k]="<<g[i].s2[k]<<endl;
//					cout<<(k<j)<<" "<<(k>j+g[i].s2.size()-1)<<endl;
				}
//				cout<<"s="<<s<<endl;
				if(s==t2) ans++;
//				cout<<t<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}