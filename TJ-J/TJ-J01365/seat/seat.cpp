#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,a[101]={0},ci=1,lie=0,ge=0,hang=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[1]<a[i]){
			ci++;
		}
	}
	
	if(ci%n==0){
		lie=ci/n;
	}
	if(ci%n!=0){
		lie=ci/n+1;
	}
	ge=ci%n;
	if(lie%2==0){
		hang=n-ge+1;
		cout<<lie<<" "<<hang;	
	}
	if(lie%2!=0){
		hang=ci%n;
		if(hang==0)
			cout<<lie<<" "<<n;
		else
			cout<<lie<<" "<<hang;
	}
	
	return 0;
}
