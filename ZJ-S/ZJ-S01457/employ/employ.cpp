#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int c[N];
ll jc[N];
int k[N];
int a[15],ans;
bool vis[15];
bool check(){
	for(int i=0;i<n;i++){
		if(s[i]!='1') return false;
	}
	return true;
}
void init(){
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
		//cout<<jc[i]<<"\n";
	}
	return;
}
void solve1(){
	//cout<<"solve1\n";
	if(!check()||c[1]==0){
		printf("0\n");
		return;
	}
	else{
		ll ans=jc[n];
		printf("%lld\n",ans);
		return;
	}
	return;
}
void f(int k,int n){
	if(k>n){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<"~"<<c[a[i]]<<" ";
			if(s[i-1]=='1'&&cnt1<c[a[i]]){
				cnt2++;
			}
			else cnt1++;
		}
		//cout<<cnt2<<"\n";
		if(cnt2>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[k]=i;
			vis[i]=1;
			f(k+1,n);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	init();
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') cnt1++;
		if(c[i]!=0) cnt2++;
	}
	if(min(cnt1,cnt2)<m){
		printf("0");
		return 0;
	}
	if(m==n) solve1();
	f(1,n);
	printf("%d",ans);
	return 0;
}