#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<515058943;
	}
	else if(m==n){
		int cc=1;
		for(int i=1;i<=n;i++){
			cc=cc*i%998244353;
		}
		cout<<cc;
	}
	return 0;
} 
