#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin >> n >> m;
	cin>> s;
	int a[505];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int len=s.size();
	int b=0;
	for(int i=0;i<len;i++){
		if(s[i]!=1){
			b==1;
		}
	} 
	
	if(b==0){
		long long ans=1;
		int n1=n;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout << ans;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
