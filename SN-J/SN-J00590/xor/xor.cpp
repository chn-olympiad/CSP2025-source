// Àî¿¥Ãú 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
long long aa;
int asd(int x,int y){
	if (x==y){
		return a[x];
	}
	return a[x]^asd(x+1,y); 
}
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (asd(i,j)==m){
				aa++;	
				i=j+1;
			}
		}
	}
	cout << aa;
	return 0;
}

