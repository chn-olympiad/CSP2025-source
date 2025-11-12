#include<bits/stdc++.h>
using namespace std;
bool mp[505];
int n,m;
long long ans,v[505],ch[505];
string a;
int judge1(){
	int tt=0,jj=0;
	for(int i=1;i<=n;i++){
		if(jj>=m)return 1;
		if(a[i-1]-'0'==0){
			tt++;
			continue;
		}
		if(tt<ch[i]){
			jj++;
			continue;
		}
		return 0;
	}
	if(jj<m)
		return 0;
	return 1;
}
void check(int step){
	if(step==n+1){
		ans+=judge1();
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(mp[i]==0){
			mp[i]=1;ch[step]=v[i];
			check(step+1);
			mp[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	check(1);
	cout<<ans<<endl;
	return 0;
}
