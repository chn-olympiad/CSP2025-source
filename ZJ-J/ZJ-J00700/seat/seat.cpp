#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=1e9;
int n,m,a[N],x,cnt,ex,ey,p; 
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			p=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(p==cnt){
					cout<<i<<" "<<j;
					return;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(p==cnt){
					cout<<i<<" "<<j;
					return;
				}
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
8:58 É±T2 
²Å320pts£¬ÒªAFOÁË55555555555 
*/
