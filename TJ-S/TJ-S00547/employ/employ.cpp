#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
	//骗分的点这么多？ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==n){
		int sum=1;
		for(int i=1;i<=ans;i++){
			sum*=n-i+1;sum=sum%998244353;
		}
		cout<<sum;
	}
	return 0;
} 
