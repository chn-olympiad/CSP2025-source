#include<bits/stdc++.h>
using namespace std;
int n,m,r,k;
int a[200];
bool cmp(int x,int y){
	if(x>y) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	r=a[0];
	sort(a,a+n*m-1,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			k=i+1;	
			break;
		} 
	}
	int l=(k-1)/n+1;
	int s;
	if(l%2==0) s=(n+1)-(k-(l-1)*n);
	else s=k-(l-1)*n;
	cout<<l<<" "<<s;
	return 0;
}
