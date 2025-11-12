#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		cin>>t[1]>>t[2];
		t[1]=' '+t[1];
		t[2]=' '+t[2];
		string x,y;
		ans=0;
		int cnt=0;
		ans+=cnt*(cnt+1);
		for(int i=1;i<t[1].size();i++){
			if(t[1][i]!=t[2][i]&&t[1][i-1]==t[2][i-1]){
				x+=t[1][i];
				y+=t[2][i];
			}
			if(t[1][i+1]==t[2][i+1]){
				for(int i=1;i<=n;i++)
					if(s[i][1]==x)cnt++;
			}	 
		}
		cout<<ans<<'\n';
	}
	return 0;
}

