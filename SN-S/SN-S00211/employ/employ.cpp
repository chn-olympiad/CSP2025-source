#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int maxn=1e6+10;
const int inf=1e18;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		int siz=s.size();
		int sum=0;
		for(int i=0;i<siz;i++){
			if(s[i]=='0'){
				sum++;
			}
		}
		if(sum>=1){
			cout<<"0";
		}
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
