#include<bits/stdc++.h>
using namespace std;
int n,k,a[514514],sun[514514],dp[514514];
bool fB,fA,f;int ans;
struct node{
	int s,t;
}b[500005];
void dfs(int x,int summ){
	if(summ+n-x+1<=ans)return ;
	if(b[x].t==0||b[x].t==n){
		ans=max(ans,summ);
		f=1;
		return ;
	}
	for(int i=b[x].t+1;i<=n;i++){
		if(b[i].t!=0)dfs(i,summ+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];sun[i]=sun[i-1]^a[i];
		if(a[i]!=1)fA=1;
		if(a[i]!=1&&a[i]!=0)fB=1;
	}
	if(!fA){
		if(k>1)cout<<0;
		else if(k==1)cout<<n;
		else cout<<n/2;
		return 0;
	}
	if(!fB){
		if(k>1)cout<<0;
		else if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++)if(a[i]==1)sum++;
			cout<<sum;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0||(a[i]==1&&a[i-1]==1))sum++;
			}
			cout<<sum;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i].s=i;
		for(int j=i;j<=n;j++){
			if((sun[j]^sun[i-1])==k){
				b[i].t=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,1);
	}
	if(f)cout<<ans;
	else cout<<0;
}
/*
完蛋，连T3都不会了，不过反正快退役了，那就用最后10分钟写个总结吧。
可能是水文章广场水太多了，现在已经变成奶龙了QAQ，预估只有100+100+30+40=270了，这下J一等也没了QAQ算了，就当给下午的S积攒人品吧
今年的小学生一个也没了，分数线肯定要到300了，我这种废物也许也就只能学学文化课了吧……
唉，T3应该是个DP。但我一点都想不出来，也许还是太菜了QAQ。
退役之前最后的愿望就是上各省CSP迷惑行为大赏，故作此文……
我这种人还有什么用！单一个废物罢了…… 
*/
