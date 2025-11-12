#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string s1[N],s2[N]; 
inline void solve(){
	string t1,t2;int len=0,ans=0;
	cin>>t1>>t2;len=t1.size();
	for(int i=0;i<len;i++){
		bool yet=0;
		for(int k=0;k<i;k++){
			if(t1[k]!=t2[k]){
				yet=1;break;
			}
		}
		if(yet)break;
		for(int j=len-1;j>=i;j--){
			yet=0;
			for(int k=0;k<i;k++){
				if(t1[k]!=t2[k]){
					yet=1;break;
				}
			}
			for(int k=j+1;k<len;k++){
				if(t1[k]!=t2[k]){
					yet=1;break;
				}
			}
			if(yet)break;
			string ask="",to="";
			for(int k=i;k<=j;k++){
				ask+=t1[k];to+=t2[k];
			}
			for(int i=1;i<=n;i++){
				if(ask==s1[i]&&to==s2[i])ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main (){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--)solve();
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/