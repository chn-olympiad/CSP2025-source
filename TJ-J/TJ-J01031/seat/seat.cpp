#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n,m;
int a[1145];

bool cmp(int a,int b) {
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i =0;i<n*m;i++){
		cin >> a[i];
	}
	int c = a[0];
	sort(a,a + n*m,cmp);
	int ind; 
	for(int i =0;i<n*m;i++){
		if(a[i] == c){ind = i;break;}
	}
	int mo = ind % n,d = ind / n;
	if(d % 2 == 0) cout << (d + 1) << " "<<(mo + 1);
	else cout << (d + 1) << " "<< n - mo;
	return 0;
}
