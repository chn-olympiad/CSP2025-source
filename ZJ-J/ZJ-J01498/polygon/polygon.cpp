#include<bits/stdc++.h>
using namespace std;

const int maxn=5005;
long long n,ans,len;
long long k=998244353;

struct sticks{
	long long num,pos;
	bool vis;
}a[maxn];

void dfs(long long templen, long long maxstick, long long sticklen, long long p){
	if(templen==len){
		if(sticklen>maxstick*2) ans=(ans+1)%k;
		return;
	}
	for(long long j=p+1;j<=n;j++){
		if(a[j].vis==0){
			long long temp=a[j].num;
			if(temp>maxstick) maxstick=temp;
			a[j].vis=1;
			sticklen+=temp;
			p=a[j].pos;
			dfs(templen+1,maxstick,sticklen,p);
			a[j].vis=0;
			sticklen-=a[j].num;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i].num;
		a[i].vis=0;
		a[i].pos=i;
	}
	for(long long i=3;i<=n;i++){
		len=i;
		dfs(0,0,0,0);
	}
	cout << ans;
	return 0;
}
