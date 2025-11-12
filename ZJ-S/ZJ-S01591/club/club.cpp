#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int dp[maxn];
int ans=0;
int one[maxn],two[maxn],three[maxn];//cun,fang,man,yi,cheng,du
int n=0,cnt=0;
int o_a,t_b,t_c,maxxz;//mei,ge,bu,meng,yi,jing,ren,shu
bool cmp(int x,int y){
	return x>y;
}
int dfs(int now,int nowans){
	cout<<nowans<<" ";
	if(now==n+1){
		ans=max(ans,nowans);
		return dfs(--now,nowans-cnt);
	}
	if(o_a<maxxz){
		o_a++;
		cnt=one[now];
		nowans+=cnt;
		dfs(++now,nowans);
	}else if(t_b<maxxz){
		t_b++;
		cnt=two[now];
		nowans+=cnt;
		dfs(++now,nowans);
	}else if(t_c<maxxz){
		t_c++;
		cnt=three[now];
		nowans+=cnt;
		dfs(++now,nowans);
	}
}
int ve[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		maxxz=n/2;//zui,da,xian,zhi
		for(int j=1;j<=n;j++){
			cin>>one[j]>>two[j]>>three[j];
			ve[i]=one[j];
		}
	}
	sort(ve+1,ve+n+1,cmp);
	for(int i=1;i<=maxxz;i++){
		ans+=ve[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

