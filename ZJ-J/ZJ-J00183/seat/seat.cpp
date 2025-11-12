#include<bits/stdc++.h>
using namespace std;
int n,m;
int ra,rid;
struct node{
	int s,id;
};
bool cmd(node x,node y){
	return x.s>y.s;
}
node a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	ra=a[1].s;
	sort(a+1,a+1+n*m,cmd);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].s<<' ';
//	}
	int r=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<c<<' '<<r;
			return 0;
		}
		int p;
		if(c%2){
			p=1;
		}
		else{
			p=-1;
		}
		if(r+p>=1&&r+p<=n){
			r+=p;
		}
		else{
			c++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
