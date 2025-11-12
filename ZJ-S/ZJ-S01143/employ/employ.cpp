#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,c[N],cnt,ans;
bool b[N],checkA=1;
string s;
int a[N],d[N];
bool check(){
	int gu=0,sum=0;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		
		if(gu>=a[i]||b[i]==0){
			gu++;
		}else{
			sum++;
		}
		if(sum>=m)return 1;
	} 
	return 0;
}
void dfs(int k){
	if(k==n+1){
		if(check()){
			ans++;
		}
		return;	
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			d[i]=1;
			a[k]=c[i];
			dfs(k+1);
			d[i]=0;
			
		}
		
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0';
		if(b[i+1]==0){
			checkA=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+m);
	if(checkA){
		int sum=1;
		for(int i=2;i<=n;i++){
			sum=sum*i%mod;
		}
		cout<<sum;
	}else if(m==1){
		
	}else if(n<=10){
		dfs(1);
		cout<<ans;
	}
	return 0;
}


