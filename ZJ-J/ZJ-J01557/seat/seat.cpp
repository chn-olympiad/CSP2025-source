#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,x;
}a[1005];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int op=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			op=i;
			break;
		}
	}
	if(op%n==0){
		if((op/n)%2==0){
			cout<<op/n<<" "<<1;
		}else{
			cout<<op/n<<" "<<n;
		}
	}else{
		if((op/n+1)%2==0){
			cout<<op/n+1<<" "<<n-op%n+1;
		}else{
			cout<<op/n+1<<" "<<op%n;
		}
	}
}
