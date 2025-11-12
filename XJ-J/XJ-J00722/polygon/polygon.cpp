#include<iostream>
#define LL long long
using namespace std;
const int N=5010;
const int mod=998244353;
int n;
int a[N];
int sum[N];
bool flag=true;
void solve1(){
	LL ans=0;
	for(int len=3;len<=n;len++){
		LL cnt=1,now=1;
		for(int i=1;i<=len;i++){
			cnt=(cnt*(n-i+1));
			while(cnt%now==0&&now<=len){
				cnt=(cnt/now);
				now++;
			}
			cnt%=mod;
		}
		ans=(ans+cnt)%mod;
	}
	cout<<ans;
	return ;
}
LL DFS(int now,int num){
	if(now==0){
		if(num<=0) return 1;
		else return 0;
	}
	LL ans=0;
	ans=(ans+DFS(now-1,num))%mod;
	ans=(ans+DFS(now-1,num-a[now]))%mod;
	return ans%mod;
}
void solve2(){
	LL ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		ans=(ans+DFS(i,2*a[i]+1))%mod;
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		solve1();
		return 0;
	}
	if(n<=20){
		solve2();
		return 0;
	}
	return 0;
} 
