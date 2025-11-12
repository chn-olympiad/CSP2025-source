#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
const int N = 1e5+50;
const int mod = 998244353;
using namespace std;
ll n,m,ans,now;
string s;
bool vis[N];
ll a[N],b[N];

void dfs(int x,int y){
	if(x==n+1&&y>=m){
		ans++;
		ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]-now>0){
//				cout<<i <<" " <<x <<endl;
				if(s[x-1]-'0'==0){
					now++;
					dfs(x+1,y-1);
					now--;
				}
				else dfs(x+1,y);
			}
			else{
				now++;
				dfs(x+1,y-1);
				now--;
			}
			vis[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >>m >>s;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int i=0;i<n;i++){
		if(s[i]=='0') b[i+1]++;
		b[i+1]+=b[i];
	}
	sort(a+1,a+n+1);
	if(b[n]==0){
		ll lp,sum=1,lx;
		for(int i=n;i>=n-m+1;i--){
			sum*=(n-i+1); 
			lp=a[i]-1;
		}
		lx=lp;
		for(int i=1;i<=n;i++){
			if(!a[i]) lp--;
			else break;
		}
		lx=lx-lp;
		if(lp<0){
			cout <<0 <<endl;
			return 0;
		}
		else{
			dfs(1,n);
			cout <<ans <<endl;
		}
		return 0;
	}
	if(m==1){
		ll sum=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				for(int j=n;j>=1;j--){
					if(a[j]>i+1)sum++;
					else break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=mod;
		}
		cout <<sum <<endl;
		return 0;
	}
	if(m==n){
		if(a[1]==0){
			cout <<0 <<endl;
			return 0;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout <<0 <<endl;
				return 0;
			}
		}
		cout <<1 <<endl;
		return 0;
	}
	dfs(1,n);
	cout <<ans <<endl;
	return 0;
}
