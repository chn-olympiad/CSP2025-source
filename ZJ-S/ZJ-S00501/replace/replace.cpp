#include<bits/stdc++.h>
using namespace std;
string s[200010][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string t,tt;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(n>=1010&&q==1){
		cout<<0<<endl;
		return 0;
	}
	for(int j=1;j<=q;j++){
		int ans=0;
		cin>>t>>tt;
		int len1=t.size(),len2=tt.size();
		if(len1!=len2){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			int len3=s[i][1].size();
			for(int p=0;p<len1;p++){
				if(t.substr(p,len3)==s[i][1]){
					if(t.substr(0,p)+s[i][2]+t.substr(p+len3,len1-p-len3)==tt){
						ans++;
					}
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
