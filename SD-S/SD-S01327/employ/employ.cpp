#include<bits/stdc++.h>
#define int long long
#define M 998244353
using namespace std;
const int N=1e3+10;
string s;
int a[N];
int id=-1;
void sub1(int n,int m){
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			id=i;break;
		}
	}
	if(id==-1) return;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=id) cnt++;
	}
	int ans=cnt;
	for(int i=1;i<n;i++){
		ans=(ans*i)%M;
	}
	cout<<ans<<"\n";
	
}
//void sub2(int n,int m){
//	bool fla=1;int cnt=0
//	for(int i=1;i<=n;i++){
//		if(a[i]>0) fla=0,cnt++;
//	}
//	if(fla){
//		cout<<0<<"\n";return;
//	}
//	ans=cnt;
//	
//	
//}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool flg=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') flg=0;
	}
	if(m==1){
		sub1(n,m);
		if(id==-1) cout<<0<<"\n";
		return 0;
	}
//	else if(flg){
//		sub1(n,m);
//		if(id==-1) cout<<0<<"\n";
//		return 0;
//	}
	
	
	
	

	return 0;
}

