#include<bits/stdc++.h>
using namespace std;
int n,m,t;
struct node{
	int x,num;
}a[110];
bool cmp(node y,node z){
	return y.x>z.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			t=i;
			break;
		}
	}
	t--;
	if((t/n)%2==0){
		cout<<t/n+1<<" "<<t%n+1;
	}else{
		cout<<t/n+1<<" "<<n-t%n;
	}
	return 0;
}
