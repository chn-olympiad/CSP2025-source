#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2,tt1,x,z;
int main()
{
 	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
 	cin>>n>>q;
 	for(int i=1;i<=n;i++)
 		cin>>s1[i]>>s2[i];
 	while(q--)
 	{
 		ans=0;
		cin>>t1>>t2;
		tt1=t1;
		for(int i=1;i<=n;i++)
		{
			if(t1.find(s1[i])||t1==s1[i])
			{
				int l=t1.find(s1[i]);
				x=t1.substr(0,l);
				z=t1.substr(l+s1[i].size(),t1.size()-1);
				t1="";
				t1+=x;
				t1+=s2[i];
				t1+=z;
				t1=x+s2[i]+z;
			}
			//cout<<"@@@"<<t1<<endl;
			if(t1==t2)
				ans++;
			t1=tt1;x="";z="";
		}
		cout<<ans<<endl;
	}
    return 0;
}
