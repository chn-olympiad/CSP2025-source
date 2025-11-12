#include <bits/stdc++.h>
using namespace std;
long long n,q,ans;
string s1[200000+5],s2[200000+5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int qq=1;qq<=q;qq++)
	{
		string t,t1,t2;
		cin>>t>>t1;
		t2=t;
		ans=0;
		for(int i=0;i<t2.length();i++)
		{
			t=t2;
			string x="";
			for(int num=1;num<=n;num++){
				t=t2;
				x="";
				for(int j=i;j<=i+s1[num].length()-1;j++){
					x=x+t[j];
				}
				if(x==s1[num])
				{
					for(int j=i;j<=i+s1[num].length()-1;j++){
						t[j]=s2[num][j-i];
					}
					if(t==t1)ans++; 
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
