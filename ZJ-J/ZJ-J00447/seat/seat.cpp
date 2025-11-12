#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,k,h,l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			k=i;
			break;
		}
	}
	l=k/(n*2)*2;
	k=k%(n*2);
	if(!k){
		h=1;
	}else if(k<=n){
		l++;
		h=k;
	}else{
		l+=2;
		k-=n;
		h=n-k+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
