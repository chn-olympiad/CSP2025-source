#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,sum=0,cnt=0,maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			sum+=a[j];
			if(maxx<a[j]){
				maxx=a[j];
			}
		}
		for(int j=1;j<=i;j++){
			if(sum>maxx*2){
			cnt++;
			}
		}
		sum=0;
		maxx=0;
	}
	cout<<cnt;
	return 0;
}