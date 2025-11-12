#include<bits/stdc++.h>
using namespace std;
int a[110];
int s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int d=a[0];
	int t=1;
	sort(a,a+n*m,cmp);
	int p=0;
	for(int i=1;i<=m;i++){
		if(t==1){
			for(int j=1;j<=n;j++){
				if(a[p]==d){
					cout<<i<<" "<<j;
				}
				s[i][j]=a[p];
				p++;
			}
		}
		else if(t==0){
			for(int j=n;j>=1;j--){
				if(a[p]==d){
					cout<<i<<" "<<j;
				}
				s[i][j]=a[p];
				p++;
			}
		}
		if(t==0)t=1;
		else t=0;
	}
	return 0;
}
