#include <bits/stdc++.h>
using namespace std;
int mp[15][15];
int a[105];
int num;
int zhi,shu;
int cnt[105];
int main (){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	int c,r;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
		int b=a[i];
		cnt[b]++;
	}
	zhi=a[1];
	for(int i=100;i>zhi;i--){
		shu+=cnt[i]; 
	}
	c=shu/n+1;
	if(c%2==0){
		int b=shu%n;
		r=n-b;
	}else{
		r=shu%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
