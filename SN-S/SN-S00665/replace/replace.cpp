#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[10001],b[10001],c[10001],d[10001];
struct a{
	string sa,sb;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= q;i++){
		cin >> c[i] >> d[i];
	}
	for(int i = 1;i <= N;I++){
		if(a[i] == b[i]){
			a[i] = b[i];
		}
	}
	return 0;
}
