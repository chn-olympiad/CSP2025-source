//SN-S00040
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],t[200005],k1,k2,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
	while(q--){
		cin>>k1>>k2;
		for(int i=1;i<=n;i++)
			if(k1.find(s[i])){
				int pos=k1.find(s[i]);
				for(int j=pos;j<=pos+s[i].size()-1;j++) k1[j]=t[i][j-pos+1];
				if(k1==k2){
					ans++;
					continue;
				}
			}	
	}
	cout<<ans;
	return 0;
}
