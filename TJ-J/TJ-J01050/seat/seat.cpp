#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	int a1=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		if(a[0]<a[i])a1++;
	}
	int h,l;
	h=a1/n+1;
	if(a1%n==0){
		h--;
	}
	if(h%2==0){
			l=n-a1%n+1;
		}else{
			l=a1%n;
		}
	cout<<h<<" "<<l;
	return 0;
}
