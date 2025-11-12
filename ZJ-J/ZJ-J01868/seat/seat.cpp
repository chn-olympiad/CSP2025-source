#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tgt=a[1],p=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==tgt){
			p=n*m-i+1;
			break;
		}
	}
	int l=(p-1)/n+1;
	cout<<l<<" "<<((l%2==0)?(l*n-p+1):(p-l*n+n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
