#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int tx=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int ai=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				ai++;
				if(a[ai]==tx){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ai++;
				if(a[ai]==tx){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
