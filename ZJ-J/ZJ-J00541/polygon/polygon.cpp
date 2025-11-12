#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
int n;
bool is_all_one=1;
vector<int> a,d;
bool cmp(int x,int y){
	return x<y;
}
int lowbit(int x){return x&-x;}
long long c(int n,int m){
	int ans_1=1;
	for(int i=n;i>=n-m+1;i--){
		ans_1*=i;
		ans_1%=Mod;
	}
	int ans_2=1;
	for(int i=m;i>=1;i--)ans_2*=i,ans_2%=Mod;
	return ans_1/ans_2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long ans=0;
	scanf("%d",&n);
	a.resize(n);
	d.resize(pow(2,n));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)is_all_one=0;
	}
	if(is_all_one){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=Mod;
		}
		printf("%d",ans);
		return 0;
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=pow(2,n);i++){
		int cnt=0;
		for(int j=i;j;){
			if(j%2==1)cnt++;
			j/=2;
		}
		if(cnt<3)continue;
		int maxx=a[lowbit(i)];
		if(d[i-lowbit(i)]>maxx)ans++;
		ans%=Mod;
		d[i]=d[i-lowbit(i)]+maxx;
	}
	printf("%d",ans);
	return 0;
}
