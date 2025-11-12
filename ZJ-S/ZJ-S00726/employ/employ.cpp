//Welcome to my code.(^.^)/
// u see,it is a fake and so bad code,hoping u can see something ineresting in it.Have a good time!

/*
a small stage
but it was deleted,xd.
*/
#include<stdio.h>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)

const int N=1e5+10,mod=998244353;

int n,m,c[N],s[N],vis[N],b[N];

long long ans=0;

void dfs(int k){
	if(k==n+1) {
		int lose=0,win=0;
		rep(i,1,n) {
			if(s[i]==0) {
				lose++;
				continue;
			}
			if(lose>=c[b[i]]) lose++;
			else win++;
			if(win>=m) {
				ans++;
				return;
			}
		}
		return;
	}
	rep(i,1,n) {
		if(vis[i]) continue;
		vis[i]=1,b[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}

int main() {
	int flag=1;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		scanf("%1d",&s[i]);
		if(!s[i]) flag=0;
	}
	int cnt=0;
	rep(i,1,n) {
		scanf("%d",&c[i]);
		if(!c[i]) cnt++;
	}
	if(flag==1) {
//		return 0;
//		if(cnt<m) return printf("0"),0;
//		printf("%d ",cnt);
		long long t=1;
		while(cnt--) t=t%mod*(cnt+1)%mod;
		ans=t;
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
//ah...啊 唉……
/*
打个标记
//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen() 
//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen() 
//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen() 
//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen() 
//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen() 
//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen()//freopen() 

写游记吧，摆烂了
红色的dev-c++还打不了中文
T1想到解法花了十几分钟，也还好。然后呢，实现花了一个来小时，我也是唉……
现在17:01了，还是只做出了T1，T2做了一下特殊性质A，然后呢样例都没过，有几个测试点没乡村的，就是裸的最小生成树板子，可是啊
打到一半，忘掉了，呵呵
T3看不懂，T4更闷逼，特殊性质打不了，我真是个S (9+4)  (谁知道代码里写脏话会怎么样，反正我不敢试咯) 
不管咯，摆烂吧。 
现	17:06 
17:14 Kruskal裸的板子想起来了，就是不知道对不对
17:15 吃根士力架
17:18 留一点待会吃
17:19 继续想T2吧
17:24 两个选择 op1 继续想T2		op2 去想T3暴力 交给时间决定吧 time(0)%2+1 
17:26 结果是2，我去想T3暴力了
17:27 好像无法暴力，T3不知道要进行多少次替换，去看看特殊性质 
17:30 还有1h- 我……真的是……唉……算了算了，AFO就AFO吧，拜拜,OI
string action;
//...
if( "Away From OI" == action) printf("AFO");
//...


...
AFO....


现在是17:34，想T4暴力 
又emo了啊，呵呵
打竞赛啊，要的就是抗压能力，尤其是信息，可我还是要撑不住了呢

17:36 那么，现在干什么？在这发牢骚？
将决定交给时间吧 
time(0)%2+'1'
0:做题{0:想T2	1:想T4}
1:在这继续摆{0:发呆		1:继续写这一篇}

srand(time(0))
rand()%30
进行以上活动时间，接下来就这么干咯，一直到18:15吧
现在17:42 

时间告诉我要写这一篇再写29min
....
6
17:47 不知道干啥 
17:49 打T4暴力 ,咳咳咳，又加了点东西
17:57 赶紧打暴力 
18:02 暴力RE了 
18:04 愣住了
18:05 Debug... 
18:11 傻掉了 
18:13 过会调 
18:15 我是傻 星号 距离考试结束还有15min
18:16 DeBug 
18:18 我特喵的真是傻……文件名忘改了，怪不得一直输出0 
18:21 还能争 
18:23 放弃 
*/
