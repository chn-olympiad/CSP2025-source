#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int maxn=1e6+10;
const int inf=1e18;
int n,m;
int a[1010];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],q=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				q++;
//				cout<<a[q]<<" ";
				if(a[q]==k){
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				q++;
//				cout<<a[q]<<" ";
				if(a[q]==k){
					cout<<i<<" "<<j;
				}
			}
		}
//		cout<<"\n";
	}
	return 0;
}
//20min
