#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s[200010],t[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
	while(q--){
		string p,q;
		int ans=0;
		cin>>p>>q;
		for(int i=1;i<=1;i++){
			int x=p.find(s[i]);
			if(s[i]==p&&t[i]==q){
				ans++;
				continue;
			}
			if(x>=0&&x<=s[i].length()-1){
				string s1=p.substr(0,x);
				string s3=p.substr(x+s[i].length(),p.length()-x-s[i].length()+1);
				if(s1+t[i]+s3==q) ans++; 
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}

