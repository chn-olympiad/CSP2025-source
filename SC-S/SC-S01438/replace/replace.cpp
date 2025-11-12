#include<bits/stdc++.h>
using namespace std;
int n,q;string s[200010][2],t[2];
bool cmp(int id,int x,int y){
	for(int i = 0;i<s[x][id].size();i++)
		if(s[x][id][i]!=t[id][y+i])return false;
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i = 1;i<=q;i++){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		int ans=0,len=t[0].size(),l=len,r=0;
		for(int j = 0;j<len;j++){
			if(t[0][j]!=t[1][j])l=min(l,j),r=max(r,j);	
		}
		for(int j = 1;j<=n;j++){
			for(int k = 0;k<=len-(int)s[j][0].size();k++){
				if(k>l||k+s[j][0].size()<=r)continue;
				if(cmp(0,j,k)&&cmp(1,j,k))ans++;
			}
		}
		cout<<ans<<"\n";
	}
}