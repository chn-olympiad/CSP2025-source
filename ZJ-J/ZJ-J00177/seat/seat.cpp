#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],k,p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(a[i]==k){
			p=i;
			break;
		}
	}
	int h=p/n,l=p%n;
	if(h%2==0){
		if(l==0) cout<<h<<" "<<1;
		else cout<<h+1<<" "<<l;
	}
	else{
		if(l==0) cout<<h<<" "<<n;
		else cout<<h+1<<" "<<n-l+1;
	}
	return 0;
}
