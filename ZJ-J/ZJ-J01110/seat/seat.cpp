#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[15][15];
struct node{
	int t;
	int id;
}a[505];
bool cmp(node u,node v){
	return u.t>v.t;
}
int it_x,it_y;
int f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	it_x=1;
	it_y=1;
	f=1;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		a[i].t=x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<it_y<<" "<<it_x;	
			return 0;
		} 
		if(i%n==0 && f==1 && i%(2*n)!=0){
			f=-1;
			it_y++;
		}
		else if(i%(2*n)==0 && f==-1){
			f=1;
			it_y++;
		}
		else{
			it_x+=f;
		}
	}
	return 0;
}
