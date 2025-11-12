#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int n,m,s[N],c[N],vis[N],f=1,cnt,sum;
int A(int x){
	long long sum=1;
	for(int i=1;i<=x;i++){
		sum=sum*i%998244353;
	}
	return sum;
}
int dfs(int l){
	if(l==n+1){
		if(n-cnt>=m) sum=(sum+1)%998244353;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]++;
			int ff=0;
			if(cnt>=c[i]||s[l]==0){
				ff=1;
				cnt++;
			}
			dfs(l+1);
			if(ff) cnt--;
			vis[i]--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	string ss;
	cin>>ss;
	for(int i=1;i<=n;i++){
		s[i]=ss[i-1]-'0';
		if(s[i]!=1) f=0; 
	}
	int cntc=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cntc++;
	}
	if(m==n){
		if(!f){
			cout<<0;
			return 0;
		}
		if(cntc){
			cout<<0;
			return 0;
		}
		cout<<A(n);
		return 0;
	}
	cnt=0,sum=0;
	dfs(1);
	cout<<sum%998244353;
	//cout<<pow(2,18)*20;
//	if(f){
//		cout<<A(n-cntc);
//		return 0;
//	}
	
	return 0;
} 
