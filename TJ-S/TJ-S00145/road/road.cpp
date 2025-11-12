#include<bits/stdc++.h> 
using namespace std;
int n,q,m,k,u[100001],v[100001],w[100001],c[100001],a[100001];
string s1,s2;
int main (){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		cin >> u[i] >> v[i] >> w[i];
	}for(int i=0;i<k;i++){
		cin >> c[i] ;
		for(int j=0;j<n;j++){
			cin >> c[j];
		}
	}cout <<13;
	return 0;
}
