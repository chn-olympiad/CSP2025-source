#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200001];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int smallr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==smallr){
			int qwq;
			if(i%n==0){
				qwq=i/n;
			}
			else{
				qwq=i/n+1;
			}
			if(qwq%2==0){
				cout<<qwq<<" "<<n-i%n+1;
				return 0;
			}
			else{
				if(i<=n){
					cout<<qwq<<" "<<n-i%n;
				}
				else{
					cout<<qwq<<" "<<i%n;
				}
				return 0;
			}
		}
	}
	return 0;
}
