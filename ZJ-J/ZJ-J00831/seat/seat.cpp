#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[20050];
int x[20050];
int y[20050];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ls=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				x[ls]=i;
				y[ls]=j;
				ls++;
			}
		}
		if(i%2==1){
			for(int j=1;j<=m;j++){
				x[ls]=i;
				y[ls]=j;
				ls++;
			}
		}
	}
	int tmp=a[0];
	sort(a,a+(n*m));
	for(int i=0;i<n*m;i++){
		if(a[i]==tmp){
			cnt=(n*m)-i;
			break;
		}
	}
	cout<<x[cnt]<<' '<<y[cnt]<<endl;
	return 0;
}
