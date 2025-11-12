#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int M = 5e6+5;
int tt[N];
string s[N][2];
vector<int>pre[N];
int mt = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a,b;
	for(int i = 1;i<=n;i++){
		cin>>a>>b;
		int mn = -1,mx = 0;
		for(int j = 0;j<a.size();j++){
			if(a[j]!=b[j]){
				if(mn==-1)mn = j;
				mx = j;
			}
		}
		tt[i] = mx-mn;
		s[i][0] = a,s[i][1] = b;
	}
	for(int i = 1;i<=q;i++){
		cin>>a>>b;
		int mn = -1,mx = 0;
		for(int j = 0;j<a.size();j++){
			if(a[j]!=b[j]){
				if(mn==-1)mn = j;
				mx = j;
			}
		}
		long long ans = 0;
		for(int j = 1;j<=n;j++){
			if(mx-mn!=tt[j]){
				continue;
			}
			if(mx-mn+1>s[j][0].size()){
				continue;
			}
			for(int k = 0,l = -1;k<a.size();k++){
				if(s[j][0][l+1]!=a[k]||s[j][1][l+1]!=b[k]){
					k = k-(l-(-1))+1;
					l = -1;
				}
				if(s[j][0][l+1]==a[k]&&s[j][1][l+1]==b[k]){
					l++;
				}
				if(l==s[j][0].size()-1){
					if(k>=mx&&k-s[j][0].size()+1<=mn){
						ans++;
					}
					k = k-(l-(-1))+1;
					l = -1;
				}
			}
			//cout<<j<<" "<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}

