#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=0;
	for(int i=1,j;i<=n*m;i++){
		cin>>j;
		a[j]++;
		if(i==1){
			p=j;
		}
	}
	int sum=0;
	for(int i=p;i<=100;i++){
		sum+=a[i];
	}
	int li=(sum-1)/n+1;
	int ha=(sum-1)%n+1;
	if(li%2==0){
		ha=(n-ha)+1;
	}
	cout<<li<<" "<<ha;
}
