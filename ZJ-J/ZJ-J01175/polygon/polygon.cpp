#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],sum;
void bfs(long long z,long long maxx,int i,int b){
	for(i=i+1;i<n;i++){
		long long maxxx=max(maxx,a[i]);
		if(maxxx<z&&b>=2){
			sum++;
		}
		bfs(z+a[i],maxxx,i,b+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bfs(a[i],a[i],i,1);
	}
	cout<<sum;
	return 0;
}
