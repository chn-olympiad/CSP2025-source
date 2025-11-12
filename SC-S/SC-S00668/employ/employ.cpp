#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	string s;
	int a[100000],flag=1;
	cin>>n>>m>>s;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<s.size();i++)if(s[i]!='1')flag=0;
	
	if(m==n){
		if(flag==1)cout<<1;
		else cout<<0;
		return 0;
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;

} 
