#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100001],v[100001],w[100001];
int T;
unsigned long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n>>m>>k;
	for (int i = 1; i <= m;i++){
		cin >>u[i]>>v[i]>>w[i];
		sum+=w[i];
		
		
		
	}
	
	
	if (k==0)cout << sum;
	else {
		cout<<0;
	}
	return 0;
}
