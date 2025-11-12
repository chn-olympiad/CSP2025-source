#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct node{
	int point,id;
	bool operator <(const node &cmp)const{
		return point>cmp.point;
	}
}a[N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].point;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	int idd=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			idd=i;
		}
	}
	idd--;
	int x=1,y=1,f=0;
	while(idd--){
		if(f==0){
			if(x<n){
				x++;
			}else{
				y++;
				f=1;
			}
		}else{
			if(x>1){
				x--;
			}else{
				y++;
				f=0;
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}