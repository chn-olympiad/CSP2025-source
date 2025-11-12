#include<bits/stdc++.h>
using namespace std;
int n,m,len;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=m;j++){
			if(a[++len]==a[0]) cout<<i<<" "<<j;
		}
		i++;
		for(int j=m;j>=1;j--){
			if(a[++len]==a[0]) cout<<i<<" "<<j;
		}
	}
	return 0;
}