#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
const int MAXN=505;
const ll mod=998244353,INF=1e8;

int N,M,c[MAXN];
char s[MAXN];
ll ans,jc[MAXN],idn;
bool taskA=true;

bool cho[MAXN];
void dfs(int step,int tot,int num){
	++idn;
	if(idn>INF) return;
	if(step>N){ans+=(num>=M);ans%=mod;return;}
	if(num==M){ //已经满了
		ans+=jc[N-step+1];ans%=mod;
		return;
	}
	for(int i=1;i<=N;++i){
		if(cho[i]) continue;
		cho[i]=true;
		if(s[step]=='0') dfs(step+1,tot+1,num);
		else{
			if(tot>=c[i]) dfs(step+1,tot+1,num);
			else dfs(step+1,tot,num+1);
		}
		cho[i]=false;
	}
}
void solve1(){ //爆搜
	dfs(1,0,0);
	cout<<ans;
}
ll dp[20][300000];
vector<int> state[20];
void solve2(){ //状压
	for(int i=0;i<(1<<N);++i){
		int cnt=0;
		for(int k=0;k<N;++k){
			if((i>>k)&1) ++cnt;
		}
		state[cnt].push_back(i);
	}
	dp[0][0]=1;
	for(int i=1;i<=N;++i){ //该选第i个人了
		for(int j=0;j<i;++j){ //前面录取了j个人
			for(int k=1;k<=N;++k){ //现在选的k
				int now=j; //选了之后录取了多少个
				if(s[i]=='1'&&i-1-j<c[k]) ++now;
				for(int sta:state[i-1]){ //前面选的人的状态
					if((sta>>(k-1))&1) continue;
					dp[now][sta+(1<<(k-1))]+=dp[j][sta];
					dp[now][sta+(1<<(k-1))]%=mod;
				}
			}
		}
	}
	for(int i=M;i<=N;++i){ //选了i个人
		for(int k=0;k<(1<<N);++k) ans=(ans+dp[i][k])%mod;
	}
	cout<<ans;
}

void solveN(){ //录取每一个人
	if(!taskA){cout<<0;return;} //做不到
	for(int i=1;i<=N;++i) if(c[i]==0){cout<<0;return;}
	cout<<jc[N];
}

int cnt_c[MAXN];
void solveA(){ //所以题均可做(就看耐心了)
	for(int i=1;i<=N;++i) ++cnt_c[c[i]];
	if(!cnt_c[0]){ //所有人均可被录取
		cout<<jc[N];exit(0);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>M;
	jc[0]=1;
	for(int i=1;i<=N;++i) jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=N;++i){
		cin>>s[i];
		if(s[i]=='0') taskA=false;
	}
	for(int i=1;i<=N;++i) cin>>c[i];
	if(M==N){solveN();return 0;}
	if(N<=10){solve1();return 0;}
//	if(N<=18){solve2();return 0;}
	if(taskA) solveA();
	solve1();
	return 0;
}