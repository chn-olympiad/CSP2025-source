#include<bits/stdc++.h>
using namespace std;
const int base=31,p=1e9+7;
string a[200010][2];
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s>>t;
		if(s.size()!=t.size()) cout<<0<<"\n";
		else{
			for(int j=1;j<=n;j++){
				int l=a[j][0].size();
				for(int k=1;k<=s.size()-l+1;k++){
					if(s.substr(k-1,l)==a[j][0]){
						if(t.substr(k-1,l)==a[j][1]){
							if((s.substr(0,k-1)+a[j][1]+s.substr(k+l-1,s.size()-l-k-1))==t){
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
