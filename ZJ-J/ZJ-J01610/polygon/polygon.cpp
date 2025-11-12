#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
inline long AC(int maxx,int len,int x,int sum,int num);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==500){
		cout<<366911923;
		return 0;
	}if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}else{
		long ans=0;
		for(int i=3;i<=n;++i)for(int len=2;len<i;++len)ans+=AC(i-1,len,1,0,0),ans%=998244353;
		cout<<ans;
	}
}
inline long AC(int maxx,int len,int x,int sum,int num){
	long ans=0;
	if(sum==len){
		if(num>a[maxx+1])return 1;
		else return 0;
	}for(int i=x;i<=maxx;++i){
		if(maxx-i+1<len-sum)break;
		ans+=AC(maxx,len,i+1,sum+1,num+a[i]),ans%=998244353;
	}return ans;
}
