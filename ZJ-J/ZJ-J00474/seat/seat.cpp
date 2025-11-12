#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N=1e2+5;
PII a[N];
bool cmp(PII a,PII b){
	return a.x>b.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+1+k,cmp);
	int id=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				id++;
				if(a[id].y==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				id++;
				if(a[id].y==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
