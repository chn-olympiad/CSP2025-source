#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct man{
	ll a1[4];
}a[100010];

int t;

ll sum[5],ans,cnt1[5];

string p[5];

map <string,ll> m;

void dfs(int n,int i,int which,int cnt,bool pdd){
	if(cnt1[which] > n/2){
		return;
	}
	if(cnt == n){
		ans = max(sum[1]+sum[2]+sum[3],ans);
		return;
	}
	for(int j = 1; j <= 3-pdd; j++){
		sum[j] += a[i].a1[j];
		cnt1[j]++;
		
		dfs(n,i+1,j,cnt+1,pdd);
		cnt1[j]--;
		sum[j]-=a[i].a1[j];
	}
}

void mymemset(int n){
	ans = 0;
	for(int i = 0; i<=4;i++){
		sum[i] = 0;
		cnt1[i] = 0;
	}
	for(int  i = 1; i<=n;i++){
		for(int j = 1; j <= 3; j++){
			a[i].a1[j] = 0;
		}
	}
}
bool cmp(man x,man y){
	return x.a1[1]>y.a1[1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool pd = 0,pdd=1;
		for(int i = 1;i <= n; i++)
		{
			cin>>a[i].a1[1]>>a[i].a1[2]>>a[i].a1[3];
			if(a[i].a1[2] || a[i].a1[3]) pd = 1;
			if(a[i].a1[3]) pdd = 0;
		}
		if(!pd){
			sort(a+1,a+n+1,cmp);
			for(int i = 1; i <= n/2; i++){
				ans+=a[i].a1[1];
			}
		}else dfs(n,1,1,0,pdd);
		cout<<ans<<endl;
		mymemset(n);
	}
	return 0;//wuwuwuwu
}
