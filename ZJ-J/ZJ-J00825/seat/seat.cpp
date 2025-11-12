#include<bits/stdc++.h>
using namespace std;
int n,m,num_r,x,y;
struct student{
	int num;
	bool sf1;
}a[105];
bool cmp(student x,student y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i].num;
	}
	a[1].sf1=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].sf1){
			num_r=i;
		}
	}
	if((num_r%(2*n))<=n){
		x=(num_r/(2*n))*2+1;
		y=num_r%(2*n);
	}else{
		x=(num_r/(2*n)+1)*2;
		y=n+1-num_r%n;
	}
	cout << x << ' ' << y;
	return 0; 
}
