#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	s.clear();
	cin>>s;
	vector<int>c(n);
	int ct=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i])ct++;
	}
	unsigned long long sum=1;
	for(int i=1;i<=ct;i++){
		sum=sum*i%mod;
	}
	cout<<sum%mod<<"\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
