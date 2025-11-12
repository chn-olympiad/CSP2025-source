#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			k=m*n-i+1;
			break;
		}
	}
	int h=0,l=0;
	if(k%n==0)h=k/n;
	else h=k/n+1;
	if(h%2==1){
		l=k%n;
		if(l==0)l=n;
	}
	else{
		l=k%n;
		if(l==0)l=1;
		l=n-l+1;
	}
	cout<<h<<" "<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

