#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],s,b[15][15];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int r=a[1];
	for(int i=1;i<=sum;i++){
		for(int j=i;j<=sum;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=sum;i++){
		if(a[i]==r){
			s=i;
			break;
		}
	}
	int c;
	if(s%m==0)  c=s/m,cout<<c<<" ";
	else c=s/m+1,cout<<c<<" ";
	if(s%n==0){
		if(c%2==0) cout<<1;
		else cout<<n;
	}else{
		if(c%2==0) cout<<n-s/n;
		else{
			if((sum-s)/n==0) cout<<(sum-s)/n+1;
			else cout<<(sum-s)/n;
		}
	}
	return 0;
}