#include<bits/stdc++.h>
using namespace std;
int a[100006];
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    int n,m;
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++) cin>>a[i];
    int sum=a[1],dx=0;
    sort(a+1,a+1+x,cmp);
    for(int i=1;i<=x;i++){
      if(a[i]==sum){
      dx=i;
      break;
	}
	}
    int dy=ceil(dx*1.0/n),d=dx%n;
    if(dy%2==0){
	if(d==0)cout<<dy<<" "<<1;
	else cout<<dy<<" "<<n-d+1;
	}else{
		if(d==0)cout<<dy<<" "<<n;
		else cout<<dy<<" "<<d;
	}
	return 0;
}