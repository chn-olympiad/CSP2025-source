#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y?1:0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int R;
	int a[20000]={0};
	int b[100][100]={0};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) R=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for	(int i=1;i<=n*m;i++){
		if(a[i]==R) {
			if(i<=m){
				cout<<1<<' '<<i;
				return 0;
			}
			int j=ceil(1.0*i/m);
			int k=(i-(j-1)*n)%(m+1);
			if(j%2==1){
				cout<<j<<' '<<k;
				return 0;
			}
			else {
				cout<<j<<' '<<m-k+1;
				return 0;
			}
		}
	}
	return 0;
}
