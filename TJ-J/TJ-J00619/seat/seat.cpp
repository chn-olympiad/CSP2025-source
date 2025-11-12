#include <bits/stdc++.h>
using namespace std;
struct node{
	int sc,num;
}a[101];
bool cmp(node u,node v){
	return u.sc>v.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	bool f=1;
	for(int i=1,x=1,y=1;i<=n*m;i++){
		if(a[i].num==1){
			cout<<x<<" "<<y;
			break;
		}
		if(f)y++;
		else y--;
		if(y>m&&f==1){
			x++;
			y=m;
			f=0;
		}
		if(y<1&&f==0){
			x++;
			y=1;
			f=1;
		}
	}
	return 0;
} 
