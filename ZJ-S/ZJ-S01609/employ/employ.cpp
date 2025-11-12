#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e2+10;
int n,m,a[N],cnt;
bool vis[N];
string tt;
void quan(int t,int x,int y){
//	cout<<t<<" "<<x<<" "<<y<<" "<<tt[t]<<endl;
	if(x>=m){
//		cout<<s<<endl;
		cnt++;
		return;
	}
	if(t>n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			if(a[i]>y&&tt[t]=='1'){
				quan(t+1,x+1,y);
			}else{
				quan(t+1,x,y+1);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>tt;tt=" "+tt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	quan(1,0,0);
	cout<<cnt;
	return 0;
}

