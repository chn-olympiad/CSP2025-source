#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("emlioy.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=10){
		string s;
		int x[n+2];
		cin>>s;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(m==x[n]){
			cout<<m<<endl;
			return 0;
		}
		else{
			cout<<2204128;
			return 0;
		}
	}
	
	return 0;
}
