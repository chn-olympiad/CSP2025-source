#include<bits/stdc++.h>
using namespace std;
int n,m,x=0,y=1;
struct node{
	int id,num;
	bool operator < (const node &p) const{
		return num>p.num;
	}
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for (int i=1;i<=t;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+t+1);
	for (int i=1;i<=t;i++){
		if (y%2==1){
			x++;
			if (x>n) x=n,y++;
		}else{
			x--;
			if (x<1) x=1,y++;
		}
		if (a[i].id==1){
			cout<<y<<' '<<x<<endl;
			return 0;
		}
	}
	return 0;
}


