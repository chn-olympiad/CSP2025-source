#include<bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	
	sort(a+1,a+1+n*m,cmp);
	
	int now=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[now]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}
		else {
			for(int j=n;j>=1;j--){
				if(a[now]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}
	}
	return 0;
}
