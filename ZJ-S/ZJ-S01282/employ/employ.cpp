#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,c[maxn];
	string a;
	
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	long long suan=1,q=1,k=1;
	for(int i=1;i<=n;i++){
		suan*=i;
	}
	for(int i=1;i<=n-m;i++){
		q*=i;
	}
	for(int i=1;i<=m;i++){
		k*=i;
	}
	cout<<(suan/q/k)%998244353;
	
	
		
	
	return 0;
}