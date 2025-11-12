#include<bits/stdc++.h>
using namespace std;
struct node{
	int bh;
	int cj;
};
node a[105];
int n,m,t;
bool cmp(node x,node y){
	if(x.cj>y.cj) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i].cj;
    	a[i].bh=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].bh==1){
			t=i;
			break;
		}
	}
	cout<<(t+n-1)/n<<' ';
	t=(t-1)%(2*n)+1;
	if(t<=n){
		cout<<t;
	}else{
		cout<<2*n-t+1;
	}
	return 0;
}
