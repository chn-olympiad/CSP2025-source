#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int n,m;
int ar[105];
bool cmp(int a,int b){
	return a>b;
}
int res;
int mp[15][15];
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ar[i];
	}
	res=ar[1];
	sort(ar+1,ar+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(ar[cnt]==res) {
					cout<<i<<' '<<j<<endl;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(ar[cnt]==res) {
					cout<<i<<' '<<j<<endl;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
