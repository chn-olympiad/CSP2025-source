#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int a,b,c,cha;
}d[100010];

int t,n;
bool flag1,flag2;
long long ans;
int cnt[5];

bool cmp1(node x,node y){
	return x.a>y.a;
}

bool cmp2(node x,node y){
	return x.cha>y.cha;
}

void dfs(int num,long long tot){
	if(num==n+1){
		ans = max(ans,tot);
		return;
	}
	if(cnt[1]<n/2){
		cnt[1]++;
		dfs(num+1,tot+d[num].a);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		dfs(num+1,tot+d[num].b);
		cnt[2]--;
	}
	if(cnt[3]<n/2){
		cnt[3]++;
		dfs(num+1,tot+d[num].c);
		cnt[3]--;
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		flag1=flag2=1;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			d[i].cha = d[i].a-d[i].b;
			if(d[i].b!=0)flag1=0;
			if(d[i].c!=0)flag2=0;
		}
		if(flag1){ //5
			sort(d+1,d+n+1,cmp1);
			for(int i=1;i<=n/2;i++)ans+=d[i].a;	
		}else if(flag2){ //10
			sort(d+1,d+n+1,cmp2);
			for(int i=1;i<=n/2;i++)ans+=d[i].a;
			for(int i=n/2+1;i<=n;i++)ans+=d[i].b;
		}else if(n<=10){ //20
			dfs(1,0);
		}else{
			for(int i=1;i<=n;i++){
				ans+=max({d[i].a,d[i].b,d[i].c});
			}
		}
		printf("%lld",ans);
	}
	return 0;
}