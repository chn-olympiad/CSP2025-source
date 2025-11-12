#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,q,ans,t,x;
string a[200010],b[200010],s1,s2;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(q<=20){
			for(int l=1;l<=n;l++){
				t=0;
				for(int j=0;j<s1.size()-a[l].size()+1;j++){
					if(s1.substr(j,a[l].size())==a[l]){
						t++;
						x=j;
					}
				}
				if(t==1){
					if(s2.substr(x,b[l].size())==b[l]){
						ans++;
					}
				}	
			}
			cout<<ans<<endl;
			ans=0;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/