#include<bits/stdc++.h>
using namespace std;
int a[100100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				cnt++;
				if(a[cnt]==p){
					cout<<j<<" "<<i<<'\n';
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				cnt++;
				if(a[cnt]==p){
					cout<<j<<" "<<i<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
