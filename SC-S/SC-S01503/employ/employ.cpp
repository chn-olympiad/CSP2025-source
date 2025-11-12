#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,cnt,ans,a[505],b[505],shibai,val,con;
bool v[505];
string str;
void dfs(int depth){
	if(depth==n){
		cnt=0;
		shibai=0;
		for(int i=1;i<=n;i++){
			if((str[i-1]=='1')&&b[i]>shibai) cnt++;
			else shibai++;
			if(cnt>=m){
				ans++;
				ans%=998244353;
				return ;
			}
		}
		if(cnt>=m) ans++;
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			b[depth+1]=a[i];
			dfs(depth+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	if(n<m){
		cout<<0;
		return 0;
	}
	for(int i=str.size()-1;i>=0;i--) if(str[i]=='1') cnt++,val=i;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(cnt==1){
			if(a[i]>val){
				con++;
			}
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(cnt==1&&m==1){
		ans=con;
		n-=1;
		while(n){
			ans*=n;
			ans%=998244353;
			n--;
		}
		cout<<ans;
		return 0;
	}
	else if(cnt==1&&m>1){
		cout<<0;
		return 0;
	}
	dfs(0);
	printf("%d",ans);
}