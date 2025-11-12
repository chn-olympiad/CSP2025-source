#include<bits/stdc++.h>
using namespace std;
long long a[505];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,sum;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long k=0;
	for(long long j=1;j<=m;j++){
		if(j%2==1){
			for(long long i=1;i<=n;i++){
				k++;
				if(a[k]==sum){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else{
			for(long long i=n;i>=1;i--){
				k++;
				if(a[k]==sum){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}

