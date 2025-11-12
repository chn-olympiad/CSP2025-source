#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,x;
}a[105];
int n,m;
bool cmp(node xx,node y){
	return xx.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+h+1,cmp);
	int x=1,y=1;
	bool t=1;
	for(int i=1;i<=h;i++){
		if(a[i].id==1){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		if(x==n&&t){
			y++;
			t=!t;
			continue;
		}
		if(x==1&&!t){
			y++;
			t=!t;
			continue;
		}
		if(t)x++;
		else x--;
	}
	return 0;
}