#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int b1,int b2){
	return b1>b2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	int j1=0;
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			j1=i;
			break;
		}
	}
	int l=ceil(j1*1.0/m);
	int h=0;
	if(l==1){
		cout<<l<<" "<<j1;
		return 0;
	}
	if(l%2!=0){
		h=j1-j1/n*n;
		if(h==0){
			cout<<l<<" "<<n;
			return 0;
		} 
		cout<<l<<" "<<h;
		return 0;
	}
	h=n-(j1-j1/n*n)+1;
	cout<<l<<" "<<h;
	return 0;
}