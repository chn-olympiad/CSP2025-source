#include<bits/stdc++.h>
using namespace std;
int n,m,l,ans;
string s;
int a[505],b[505];
bool vis[505];
const int mod=998244353;
void dfs(int x){
	if(x>n+1) return;
	if(l==n){
		int sum=0;
		int p=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||a[b[i]]-p<=0) {
				p++;
			} else{
				sum++;
			}
		//	cout<<b[i]<<" ";
		}
		//cout<<sum<<endl;
		if(sum>=m) ans++;
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			b[++l]=i;
			vis[i]=1;
			dfs(x+1);
			--l;
			vis[i]=0;
		}
		
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=12){
		dfs(1);
		printf("%d",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') sum++;
	}
	if(sum==s.size()){
		long long ans=1LL;
		for(int i=2;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
		printf("%lld",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==1){
		long long ans=1LL;
		for(int i=2;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
		printf("%lld",ans);	
	}
	if(m==n){
		printf(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

