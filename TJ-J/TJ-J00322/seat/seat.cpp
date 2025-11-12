#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],f;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,k=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--,k++){
				if(a[k]==s){
					cout<<i<<' '<<j;
					f=1;
					break;
				}
			}
		}else{
			for(int j=1;j<=n;j++,k++){
				if(a[k]==s){
					cout<<i<<' '<<j;
					f=1;
					break;
				}
			}
		}
		if(f) break;
	}
	return 0;
}

