#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);

	int n,m;
	string s;
	cin>>n>>m>>s;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		int p=1;
		for(int i=1;i<n;i++){
			p*=n;
			p=p%998244353;
		}
		cout<<p;
	}else{
		int p=0,tp=0,fp=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				tp++;
			}else if(a[i]<=fp){
				fp++;
			}else{
				fp++;
			}
		}
		cout<<p%998244353;
	}

	return 0;
}

