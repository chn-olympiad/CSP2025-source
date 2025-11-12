#include<bits/stdc++.h>
using namespace std;
int n,T;
const int N=2e5+10;
string s[N][2];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(T--){
		cin>>a>>b;
		int r=0;
		bool t=0;
		for(int i=1;i<=n;i++){
			if(a==b){
				r++;
				continue;
			}
			int k=a.find(s[i][0]);
			while(k!=-1){
				if(a.substr(0,k)+s[i][1]+a.substr(k+s[i][0].size(),a.size()-(k+s[i][0].size()))==b){
					r++;
					t=1;
					break;
				}
			}
		}
		cout<<r<<"\n";
	}
	return 0;
}
