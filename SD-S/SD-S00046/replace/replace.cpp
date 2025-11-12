#include<bits/stdc++.h>
#define int long long
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define endl '\n'
using namespace std;

int n,q;
string s[214514][2],qs[2145149][2];


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	FILE("replace")
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
//		cout<<s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i][0]>>qs[i][1];
	}
	
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int x=qs[i][0].find(s[j][0]);
			if(x==-1){
				continue;
			}
			string ss=qs[i][0];
			
			for(int k=x;k<=x+s[j][0].size()-1;k++){
				ss[k]=s[j][1][k-x];
			}
			//cout<<ss<<" ";
			if(ss==qs[i][1]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
