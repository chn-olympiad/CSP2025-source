#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s;
	int n,m,k,minf,b;
	cin>>n>>m>>k;
	int a[n],w[k];
	for(int i;i<3*n;i++){
		cin>>a[n];
	}
	for(int i;i<4*k;i++){
	cin>>w[k];
	}	
	for(int i;i<k;i++){
	minf=a[n]+w[k];
	b=b+minf;
	}
	b=b-1;
	cout<<b;
	return 0;
}

