#include <bits/stdc++.h>
using namespace std;
struct node{
	int f,id,pm;
};
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	node a[(n*m)+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].pm=i;
	}
	int sum=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			sum=a[i].pm;
		}
	}

	cout<<(sum+n-1)/n<<" ";//m
	int rm=(sum+n-1)/n;
	if(rm%2!=0)
	{
		cout<<(sum-1)%n+1;
	}
	else{
		cout<<n-(sum%n)+1;
	}
	return 0;
}
	
