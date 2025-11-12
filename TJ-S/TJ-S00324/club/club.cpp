#include<bits/stdc++.h>
using namespace std;
int T;
int a[500005],b[500005],c[500005];
long long ans;
int ja,jb,jc;
int n;
long long s;
int dp[5][500005];
void dfs(int ji){
	if(ji>n){
		if(s>ans) ans=s;
		return ;
	}
	if(ja<n/2){
		ja++;
		s+=a[ji];
		dfs(ji+1);
		s-=a[ji];
		ja--;
	}
	if(jb<n/2){
		jb++;
		s+=b[ji];
		dfs(ji+1);
		s-=b[ji];
		jb--;
	}
	if(jc<n/2){
		jc++;
		s+=c[ji];
		dfs(ji+1);
		s-=c[ji];
		jc--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		s=0;
		ja=0,jb=0,jc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	
	return 0;
}
