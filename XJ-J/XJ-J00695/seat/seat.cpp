#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,js=0;
	cin >>n>>m;
	int zzw=n*m;
	int a[zzw+1];
	for(int i=1;i<=zzw;i++){
		cin >> a[i];
	}
	R=a[1];
	sort(a+1,a+1+zzw,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				js++;
				if(R==a[js]){
					cout << i <<" "<< j;	
					return 0;
				}
			}	
		}
		else{
			for(int j=n;j>=1;j--){
				js++;
				if(R==a[js]){
					cout << i <<" "<< j;
					return 0;	
				}
			}
		}
	}
	return 0;
}
