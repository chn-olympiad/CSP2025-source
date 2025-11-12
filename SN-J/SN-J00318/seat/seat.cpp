#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num;
	bool f=0;
};
Node a[105];
bool cmp(Node x,Node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cin >> a[0].num;
	a[0].f=1;
	for(int i=1;i<n*m;i++) cin >> a[i].num;
	sort(a,a+n*m,cmp);
	int q=0;
	for(int i=0;i<n*m;i++){
		q++;
		if(a[i].f) break;                 
	}
	if(q%n==0){
		if(q/n%2==0) cout << q/n << " " << 1; 
		else cout << q/n << " " << n;
	}else{
		if((q/n+1)%2==0) cout << q/n+1 << " " << n-q%n+1;
		else cout << q/n+1 << " " << q%n;
	}
	return 0;
}
