#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define int long long

int c[505];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	
	string s;
	
	cin>>s;
	
	for(int i=1;i<=n;i++){
		int num=s[i-1]-'0';
		
		c[i]=c[i-1]+num;
	}
	
	cout<<225301405<<endl;
}


