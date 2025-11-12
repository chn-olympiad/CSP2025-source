#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int naixin[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n;i++){
		cin>>naixin[i];
	}
	int ans=1;
	for(int i=n;i>=1;i--){
		ans*=i;
	}
	cout<<ans;
} 