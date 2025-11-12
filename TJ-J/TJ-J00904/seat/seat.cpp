#include<bits/stdc++.h>
using namespace std;
struct node{
	long long score;
	long long num;
};
bool cmp(node x,node y){
	return x.score>y.score;
}
node a[1005];//m列数，n行数
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	sort(&a[1],&a[n*m+1],cmp);
	long long c=1,r=1,i=1;
	while(c*r<=n*m){
		if(a[i].num==1){
			cout<<c<<' '<<r;
			break;
		}
		i++;
		if(c%2==0){
			r--;
		}else{
			r++;
		}
		if(r>n){
			r=n;
			c++;
		}else if(r<=0){
			r=1;
			c++;
		} 
	}
	return 0;
}
