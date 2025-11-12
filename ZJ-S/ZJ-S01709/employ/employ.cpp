#include"cstdio"
#define ll long long
const int N=510;
const ll M=998244353;
int n,m,a[N];
char c[N];
ll f[272144][20],ans;
void sol15(){
	for(int i=1;i<=n;i++){
		if(c[i]=='0'||a[i]==0){
			printf("0");
			return;
		}
	}
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%M;
	printf("%lld\n",ans);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==n){
		sol15();
		return 0;
	}
	f[0][0]=1;
	for(int s=1;s<(1<<n);s++){
		int sz=0;
		for(int i=1;i<=n;i++)
			if((s&(1<<(i-1)))!=0)sz++;
		for(int i=1;i<=n;i++){
			if((s&(1<<(i-1)))!=0){
				for(int j=0;j<=n;j++){
					if(j>=a[i]||c[sz]=='0')f[s][j+1]=(f[s][j+1]+f[s^(1<<(i-1))][j])%M;
					else f[s][j]=(f[s][j]+f[s^(1<<(i-1))][j])%M;
				}
			}
		}
	}
	for(int i=0;i<=n-m;i++)
		ans=(ans+f[(1<<n)-1][i])%M;
	printf("%lld",ans);
	return 0;
}
/*
T4
17:39暴力似乎写完了。
17:44我要玩原神。
17:52写了点部分分。
17:54我要玩原神。
18:00我感觉我还能写不少分，但是真的不想写了。
18:03我要玩原神。
18:09更新了前一题的更新日志。
18:12我要玩原神。
18:23马上就可以玩原神了。
感觉我这次成绩会很烂啊，我真是太菜了。
*/
