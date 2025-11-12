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
	cin>>a[1];
	int x=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cnt=i;
		}
	}
	double l=cnt*1.0/n;
	if(l==int(l)){
		cout<<l<<" ";
		if(int(l)%2==1){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		int y=int(l);
		cout<<y+1<<" ";
		int x=cnt-int(l)*n;
		if((y+1)%2==1){
			cout<<x;
		}else{
			cout<<n-x+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
