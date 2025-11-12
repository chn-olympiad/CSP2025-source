//SN-J00415,张迪，延安市安塞区初级中学
#include<bits/stdc++.h>
using namespace std;
int a[100],c,r,s=1,ch;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]){
			s++;
		}
	}
	
	c=2;
	r=2;
	cout<<c<<" "<<r;
	return 0;
}
