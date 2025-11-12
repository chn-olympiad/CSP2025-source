#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int n,m;
int num[110];
PII vis[110];
//int a[20][20];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>num[i];
	int x=num[1];
	sort(num+1,num+1+n*m,cmp); 
	bool flag=true;
	int k=1;
	bool f=false;
	for(int i=1;;){
		if(f)break;
		for(int j=1;;){
			vis[num[k]]={j,i};
//			a[i][j]=num[k];
			if(k==n*m){
				f=true;
				break;
			}
			k++;
			if(flag)i++;
			else i--;
			if(i==n+1)flag=false,i=n,j++;
			if(i==0)flag=true,i=1,j++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	cout<<vis[x].first<<" "<<vis[x].second<<endl;
}
signed main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
