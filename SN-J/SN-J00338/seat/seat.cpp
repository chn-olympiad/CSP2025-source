//SN-J00338 张巍骞 曲江第一中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1111];
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i<= n*m; i++) {
		cin>>a[i];
	}
	int asd=  1;
	int p = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i<= n*m; i++) {
		if(a[i]==p) break;
		if(a[i]>p) {
			asd++;
		}
	}
	int y =asd/n,x = asd%n;
	if(x!=0) {
		y+=1;
	}else if(x==0){
		x = n;
	}
	if(y%2==0) {
		cout<<y<<" "<<n-x+1;
	} else {
		cout<<y<<" "<<x;
	}
	return 0;
}
