#include <bits/stdc++.h>
using namespace std;
string s[200005][5];
int n,q,ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		string a,b;
		cin>>a>>b;
		ans=0;
		for(int i=1;i<=n;i++){
			string g="";
			for(int j=0;j<a.size();j++){
				g+=a[j];
				int fl=0;
				int len=s[i][1].size();
				for(int k=j;k>=j-len+1&&j+1-len>=0;k--){
					if(g[k]!=s[i][1][k-(j+1-len)]){
						fl=1;
						break;
					}
				}
				if(j-len+1>=0&&fl==0){
					string x=a,y=b;
					for(int k=j;k>=j-len+1&&j+1-len>=0;k--){
						x[k]=s[i][2][k-(j+1-len)];
					}
					if(x==y) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/