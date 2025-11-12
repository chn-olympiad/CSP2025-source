#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q;
string s[N][3];
string t[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size()){
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			int pos=t[i][1].find(s[j][1]);
			int pos1=t[i][2].find(s[j][2]);
			bool flag=1;
			for(int k=0;k<t[i][1].size();k++){
				if(k>=pos&&k<=pos+s[j][1].size()-1) continue;
				if(t[i][1][k]!=t[i][2][k]){
					flag=0;
					break;
				}
			}
			if(pos==pos1&&pos!=-1&&flag) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
4 2
 xabcx xadex
 ab cd
 bc de
aa bb
 xabcx xadex
aaaa bbbb*/
