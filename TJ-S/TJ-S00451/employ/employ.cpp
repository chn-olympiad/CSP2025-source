#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int c[11];
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		
		if(c[i]==0) n--;
	}
	long long int sum=1;
	int x=n;
	for(int i=0;i<m;i++){
		sum*=x;
		x-=1;
	}
	cout<<sum%998244353;
	return 0;
}
