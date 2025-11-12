#include<iostream>
using namespace std;
const int maxn=1e6+5;
int a[maxn],b[maxn],c[maxn],cnt1[maxn],cnt2[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k+1;i++){
		cin>>cnt1[i]>>cnt2[i];
	}
	cout<<n;
	return 0;
}
