#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
#define mod 998244353
ll n,m,vis[N],num,c[N],sl[N],ans,tong[N],fir=0;
char s[N];
bool flag;
bool check()
{
	ll lz=0;
//	for(int i=1;i<=n;i++){
//		cout << sl[i] <<" ";
//	}
//	cout <<"\n";
	for(int i=1;i<=n;i++){
		if(c[sl[i]]<=lz||s[i]=='0'){
			lz++;
		}
	}
	if(n-lz>=m){
		return true;
	} else {
		return false;
	}
}
void dfs(ll c)
{
	if(c>n){
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sl[c]=i;
			vis[i]=1;
			dfs(c+1);
			vis[i]=0;
			sl[c]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		if(s[i]!='1'){
			flag=1;
		} else if(fir==0){
			fir=i;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
		tong[c[i]]++;
	}
	if(n<=10){
		dfs(1);
	} else if(m==n){
		if(!flag||tong[0]>0){
			ans=0;
		} else {
			ans=1;
			for(int i=1;i<=n;i++){
					ans=ans*i%mod;
				}
		}
	}
//	for(int i=0;i<=n;i++){
//		if(i!=0){
//			sl[i]=sl[i-1]+sl[i];
//		}
//		cout << sl[i] <<" " <<i <<"\n";
//	}
//	cout <<"\n";
//	if(!flag){
//		ll ans=1;
//		bool flag1=1;
//		while(flag1){
//			flag1=0;
//			for(int i=1;i<=n;i++){
//				if(c[i]<=0&&vis[i]==0){
//					num++;
//					flag1=1;
//					vis[i]=1;
//					cout << i <<" " << c[i] <<" " << num <<"\n";
//				}
//			}
//		}
//		if(0){
//			ans=0;
//		} else {
//			for(int i=1;i<=62;i++){
//				ans=ans*i%mod;
//			}	
//		}
//		cout << ans <<" " << num;
//	}
	cout << ans; 
	return 0;
} 
