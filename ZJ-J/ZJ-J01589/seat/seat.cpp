#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,d;
struct node{
	long long x,y;
}a[105];
bool cmp(node x,node y){
	return x.x > y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i].x;
		a[i].y = i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i].y == 1){
			d = i;
		}
	}
	c = ceil(d*1.0 / n);
	if(c%2 == 0){
		if(d%n == 0){
			r = 1;
		}else{
			r = n - d%n + 1;
		}
	}else{
		if(d%n == 0){
			r = n;
		}else{
			r = d%n;
		}
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
