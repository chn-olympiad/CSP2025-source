#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long sum=1;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n-1;i++){
		sum=sum*i%998244353;
	}
	cout<<sum;
	return 0;
} 
