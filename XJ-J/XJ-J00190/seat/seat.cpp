#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	int r=a[1];
	int p;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	}
	int l,h;
	int t=ceil(p/n);
	l=t+1;
	if(p%n==0){
		l--;
		h=n;
	}else{
		if(l%2==1){ 
			h=p-t*n;
		}else{
			h=n-(p-t*n)+1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
