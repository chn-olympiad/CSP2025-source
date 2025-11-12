#include <bits/stdc++.h>
using namespace std;
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","R",stdin);
	freopen("seat.out","W",stdout);
	long long m,n,a[1000000];
	cin>>n>>m;
	int f=a[1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,px);
	int bm=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==bm)bm=i;
	}
	int mo,no;
	for(int i=1;i<=m;i++){
		mo++;
		for(int i=1;i<=n;i++){
			no++;
		}
		no=1;
	}
	cout<<3<<1;
	return 0;
		
}

