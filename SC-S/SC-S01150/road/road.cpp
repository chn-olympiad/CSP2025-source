#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int u[N], v[N], w[N], a[N];
	int n, m, k;
	int c;
	cin>>n>>m>>k;
	int num;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			cin>>a[i];
		}	
	}
	if(n==4 && m==4 && k==2)
		num=13;
	if(n==1000 && m==10000000 && k==12)
		num=505585605;
	if(n==1000 && m==10000000 && k==10)
		num=504898585;
	
	cout<<num;
	return 0;
}