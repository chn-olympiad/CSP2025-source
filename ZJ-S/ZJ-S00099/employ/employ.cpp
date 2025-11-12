#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,vv,vvv;
char c;
int a[100100],b[100100],t[100100],qian[100100];
bool flag[100];
bool check(){
	int sum=0,tt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			tt++;
			continue;
		}
		if(b[t[i]]>tt) sum++;
		else tt++;
	}
	return sum>=m;
}
void dfs(int shu){
	if(shu==n){
		if(check()) vvv++;
		vvv%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			t[shu+1]=i;
			dfs(shu+1);
			t[shu+1]=0;
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>c;
			a[i]=c-'0';
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		dfs(0);
		cout<<vvv;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>c;
			a[i]=c-'0';
			if(a[i]==0) vv++;
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		if(vv==0){
			int cnt=1;
			for(int i=n;i>=1;i--){
				cnt=(cnt*i)%mod;
			}
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
