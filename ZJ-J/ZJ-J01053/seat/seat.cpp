#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,s,sh,x,r;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			s=i;
			break;
		} 	
	}
	x=s/(m*2);
	sh=s%(m*2);
	if(sh==0){
		cout<<x*2<<" "<<1;
	}
	if(sh<=m){
		cout<<x*2+1<<" "<<sh;
	}
	else{
		cout<<x*2+2<<" ";
		sh=sh-m-1;
		sh=m-sh;
		cout<<sh;
	}
}