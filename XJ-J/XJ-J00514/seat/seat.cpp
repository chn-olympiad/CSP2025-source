#include <bits/stdc++.h>
using namespace std;
int n,m,r;
int a[110];
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
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				k++;
				if(a[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
