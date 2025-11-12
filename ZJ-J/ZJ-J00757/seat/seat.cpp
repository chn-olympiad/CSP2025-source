#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			pos=i;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;){
		for(int j=1;j<=n;j++){
			cnt++;
			if(pos==cnt){
				cout<<i<<" "<<j<<"\n";
			}
		}
		i++;
		if(i>m) break;
		for(int j=n;j>=1;j--){
			cnt++;
			if(pos==cnt){
				cout<<i<<" "<<j<<"\n";
			}
		}
		i++;
	}
	return 0;
}