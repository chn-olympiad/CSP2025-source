#include<bits/stdc++.h>
using namespace std;
struct wcnm{
	string a,b;
}s[200002];
string s1,s2;
int n,q;
void solve(){
	int ans=0;
	cin>>s1>>s2;
	if(s1.size()!=s2.size()){
		cout<<"0\n";
		return ;
	}
	int len=s1.size();
	for(int i=1;i<=n;i++){
		int m=s[i].a.size();
		int temp=0;
		for(int j=0;j<=len-m;j++){
			if(s1[j]==s[i].a[0]&&s2[j]==s[i].b[0]){
				int flag=1;
				for(int k=1;k<m;k++)
					if(s[i].a[k]!=s1[j+k]||s[i].b[k]!=s2[j+k]){
						flag=0;
						break;
					}
				if(flag) temp++;
			}
		}
		if(temp==1) ans++;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b;
	while(q--) solve();
	return 0;
}
