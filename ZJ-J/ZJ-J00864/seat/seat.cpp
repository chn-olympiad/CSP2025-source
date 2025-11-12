#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,p=1,q=1;
bool tmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,tmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			break;
		}
		if(p%2==1){
			if(q!=n) q++;
			else p++;
		}else{
			if(q!=1) q--;
			else p++;
		}
	}cout<<p<<' '<<q;
	return 0;
}