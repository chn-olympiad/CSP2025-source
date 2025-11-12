#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[105];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				k++;
				if(a[k]==x){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				k++;
				if(a[k]==x){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
