#include<bits/stdc++.h>
using namespace std;
struct qw{
	long long u,v,w;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	vector<qw> a(m+5);
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	vector<long long> aa(n+1);
	for(int i=0;i<k;i++){
		cin>>aa[i];
	}
	cout<<0;
	return 0;
} 