#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x=1,y=1,flag,id;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			id=i;
			break;
		}
	}
	for(int i=1;i<id;i++){
		if(flag==0){
			if(x==n)y++,flag=1;
			else x++;
		}
		else if(flag==1){
			if(x==1)y++,flag=0;
			else x--;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
