#include<bits/stdc++.h>
//I feel not good.
//T1 and T2 is too EZ.
//There must be something extremely hard after.
//CCF!!
using namespace std;
int n,m,a[105],human,c=1,r=0;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	human=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(c%2) r++;
		else r--;
//		printf("Status temporal c=%d r=%d\n",c,r);
		if(r<1||r>n){
//			printf("Status turned around\n");
			c++;
			if(r<1) r++;
			if(r>n) r--;
		}
//		printf("Status c=%d r=%d\n",c,r);
		if(a[i]==human)	return (cout<<c<<" "<<r)&&0;
	}
	return 0;
}
