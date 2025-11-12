#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
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
	int fg=a[1];
	sort(a+1,a+n*m+1,cmp);
	int sum=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[sum]==fg){
					cout<<j<<" "<<i;
					return 0;
				}
				sum++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[sum]==fg){
					cout<<j<<" "<<i;
					return 0;
				}
				sum++;
			}
		}
	}
	return 0;
}
