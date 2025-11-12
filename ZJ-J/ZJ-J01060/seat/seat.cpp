#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int pai;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=n*m,xiaomin=a[1];
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		if(xiaomin==a[i]){
			pai=x-i+1;
			break;	
		}
	}
	int hang,lie;
	lie=(pai-1)/n+1;
	if(lie%2==1){
		hang=pai-n*(lie-1);
	}else{
		hang=n-(pai-n*(lie-1))+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
	
}
