#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=1,n,m,t;
string s;
int a[510];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			t++;
			ans*=a[i];
			ans%=mod;
		}
	}
	
	
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
