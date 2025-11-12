#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2;
string s[1008617][2];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
    while(q--)
    {
    	cin>>s1>>s2;
    	int ans=0;
    	for(int i=1;i<=n;i++)
    	{
    		int s1f=s1.find(s[i][0]),s2f=s2.find(s[i][1]);
			if(s1f==s2f&&s2f!=18446744073709551615ll&&s1f!=18446744073709551615ll)
			{
				string s3=s1;
				int len=s[i][1].length();
				for(int j=0;j<len;j++)
				{
				    s3[j+s1f]=s[i][1][j];
				}
				if(s3==s2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
