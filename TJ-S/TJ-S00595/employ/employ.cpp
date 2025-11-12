#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c,sum=1,tmp=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	for(int i=2;i<=n;i++){
		sum=(sum*i)%998244353;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
