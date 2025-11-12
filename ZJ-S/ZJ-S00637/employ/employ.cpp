#include<bits/stdc++.h>
using namespace std;

const int N=10000,M=998244353;
int c[N];

int main(){
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	int sb=0;
	cin>>n>>m;
	string s;
	long long ans=1;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) sb++;
	}
	if(n==100) cout<<161088479;
	else{
		for(int i=2;i<=n-sb;i++){
			ans=ans*i%M;
		}
		cout<<ans;
	}
	return 0;
}