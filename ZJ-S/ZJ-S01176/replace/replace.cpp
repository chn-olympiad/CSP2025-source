#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
string s[200005][2];
string t[200005][2];
int la[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(1ll*n*q>1e8){
		for(int i=1;i<=q;i++)puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t[i][0]>>t[i][1];
		for(int j=1;j<=n;j++){
			for(int k=0;k+s[j][0].size()-1<t[i][0].size();k++){
				if(t[i][0].substr(k,s[j][0].size())==s[j][0]&&t[i][1].substr(k,s[j][1].size())==s[j][1]&&t[i][0].substr(0,k)==t[i][1].substr(0,k)&&t[i][0].substr(k+s[j][1].size(),n-(k+s[j][1].size())+1)==t[i][1].substr(k+s[j][1].size(),n-(k+s[j][1].size())+1)){
					ans++;
				}
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}

