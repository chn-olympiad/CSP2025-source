#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],x,y;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int o=a[0];
	sort(&a[0],&a[n*m],cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==o){
		x=i/n+1;
			if(i%(n*2)<n){
				y=(i+1)%n;
				if(y==0)y+=n;
				break;
			}else{
				y=n-(i%n);
				break;
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
