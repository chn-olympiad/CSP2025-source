#include<bits/stdc++.h>
using namespace std;
#define P 998244353
int n,m;
int s1[505];
int a[505];
int zt[505];
int b[505];
int c[505];
int ans=0;
void bl(int x){
	if(x>n){
		int cnt1=0,cnt2=0;
//		for(int i=1;i<=n;i++) cout<<c[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			if(s1[i]==1&&cnt1<a[c[i]]) cnt2++;
			else cnt1++;
		}
		if(cnt2>=m) ans++;
	}
	for(b[x]=1;b[x]<=n;b[x]++){
		if(zt[b[x]]==0){
			c[x]=b[x];
			zt[b[x]]=1;
			bl(x+1);
			zt[b[x]]=0;
			c[x]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) s1[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=0;
//	for(int i=1;i<=n;i++){
//		if()
//	}
	bl(1);
	cout<<ans%P;
}
