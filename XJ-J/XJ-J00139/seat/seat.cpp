#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int u=x/(2*n);
	int v=x%(2*n);
	u*=2;
	u++;
	if(v==0){
		v=1;
		u--;
	}else if(v>n){
		u++;
		v-=n;
		v=n-v+1;
	}
	cout<<u<<" "<<v;
	return 0;
}
