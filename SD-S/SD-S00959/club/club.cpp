#include<bits/stdc++.h>
using namespace std;
int t,n,sum1,sum2,sum3,ans;
int id[10005];
struct node{
	int a,b,c;
}v[100005];
bool cmp(node x,node y){
	if(x.a!=y.a)return x.a>y.a;
	return x.b>y.b;
}
void dfs(int x,int sum){
	if(x>n){
		if(sum>ans) ans=sum;
		return;
	}
//	cout<<x<<' '<<sum<<' '<<sum1<<' '<<sum2<<' '<<sum3<<endl;
	if(sum1<n/2) sum1++,dfs(x+1,sum+v[x+1].a),sum1--;
	if(sum2<n/2) sum2++,dfs(x+1,sum+v[x+1].b),sum2--;
	if(sum3<n/2) sum3++,dfs(x+1,sum+v[x+1].c),sum3--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flagb=0,flagc=0;
		sum1=ans=sum2=sum3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			if(v[i].c!=0) flagc=1;
			if(v[i].b!=0) flagb=1;
		}
		// A
		sort(v+1,v+n+1,cmp);
		if(flagb==0&&flagc==0){
			for(int i=1;i<=n;i++){
				if(sum1<n/2) ans+=v[i].a,sum1++;
			}
			cout<<ans<<'\n';
			continue;
		}		
		//B
		if(flagb==1&&flagc==0){
			for(int i=1;i<=n;i++){
				if(v[i].a>v[i].b&&sum1<n/2){
					sum1++,ans+=v[i].a;
				} 
				else if(sum2<n/2) sum2++,ans+=v[i].b; 
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,0);
		cout<<ans<<'\n';
	}
	return 0;
	/*
	回顾我的OI之路 
	从六年级的小学组时 T2少考虑一种情况导致挂掉30pts 300->270 一等变二等
	到初一时CSP-J2023 T2终于想出正解却忘记给sum开longlong  200->155 一等变二等 
	再到CSP-J2024 我在考前特别紧张 甚至请了两天假在家刷题  赛时T2DFS本地爆栈可是判题机给了AC T3 cout<<8 脑子抽了写成了输出所用木棍的数量cout<<7  240->200 一等变二等
	今年 山东第一次可以双报 我便都报上了名 可是初赛我却基本没有复习 只在考前做了一套信心赛的题 况且信心赛也只拿到了65的分数
	到了初赛那天 上午考J甚至涂错卡了 好在最后90通过了 下午考S莫名其妙考了72 也过了 可我却不知为什么没有想象中的那么开心
	而如今 我再次来到了复赛的考场 入门组估分295 可提高组却狠狠打了我一巴掌 或许我真的要在下一个路口转向离开OI这条路了吧
	初三了 不早了 如果考不上qdez 那我的人生还真的有救吗？ 
	*/
}
//AFO3


