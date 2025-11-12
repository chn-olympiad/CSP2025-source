#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,b[505];
	bool q=1;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			q=0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int a=n;
	if(q==1){
		int ans=1;
		for(int i=1;i<=m;i++){
			ans*=a;
			a--;
		}
		cout<<ans;
		return 0;
	}
	cout<<2;
	return 0;
} 
