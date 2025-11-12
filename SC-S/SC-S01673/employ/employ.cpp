#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],ch[505],u,zh,s,cnt,ans;
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i = 0;i<n;i++)
		if(c[i]=='1') a[i]=1;
	for(int i = 1;i<=n;i++){
		cin>>u;
		b[u]++;
		s=max(s,u+1);
	}
	for(int i = 0;i<=s;i++){
		if(a[i]) cnt++;
		if(cnt==m) zh=i;
	}
	for(int i=s;i>=0;i--){
		ch[i]=ch[i+1]+b[i]-1;
		if(a[i]) ans*=max(1,ch[i]); 
		ans%=998244353;
	}
	for(int i=m+1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 