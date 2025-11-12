#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int k;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}int l,h;
	if(k%n) l=k/n+1;
	else l=k/n;
	if(l%2) h=k%n;
	else h=n-k%n+1;
	if(h==0) h=n;
	cout<<l<<' '<<h;
	
	
	return 0;
} 
