#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;

int n,m;
string s1[N],s2[N],t1,t2;
int ans=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> s1[i] >> s2[i];
	}
	while(m--){
		ans=0;
		cin >> t1 >> t2;
		if(t1.size()!=t2.size()){
			cout << 0 << "\n";
			continue;
		}
		for(int i=1; i<=n; i++){
			if(t1.size()<s1[i].size()) continue;
			for(int j=0; j+s1[i].size()<=t1.size(); j++){
				bool flag=0;
				string x1,x2;
				for(int q=j; q<j+s1[i].size(); q++){
					x1+=s1[i][q-j];x2+=t1[q];
					if(t1[q]!=s1[i][q-j]){
						flag=1;
						break;
					} 
				} 
				if(!flag){
					string s;
					for(int q=0; q<j; q++){
						s+=t1[q];
					}
					for(int q=j; q<j+s1[i].size(); q++){
						s+=s2[i][q-j];
					}
					for(int q=j+s1[i].size(); q<t1.size(); q++){
						s+=t1[q];
					}
					bool p=0;
					for(int q=0; q<t1.size(); q++){
						if(s[q]!=t2[q]) p=1;
					}
					if(!p) ans++; 
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
