#include<bits/stdc++.h>
using namespace std;
bool cmp(int  a, int b){
	return a>b;
}
bool cmp2(int  a, int b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[13][13],b[170],r;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	r=b[1];
	sort(b+1,b+n*m+1,cmp);
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			a[j][i]=b[(i-1)*n+j];
			if (a[j][i]==r){
				if (i%2) cout << i << " " << j;
				else cout << i <<" " << n+1-j;
				return 0;
			} 
		}
	}
	return 0;
}
