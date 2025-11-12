#include<bits/stdc++.h>
#define fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLL=pair<ll,ll>;
using PLI=pair<ll,int>;
mt19937_64 UL(time(0));
const int N=1e5+9,mod=1e9+7;
int n,m,p,k,T=1;
bool cmp(PII &x,PII &y)
{
	return x.first>y.first;
}
struct JOIN_INFM{
	//0到2
	PII a[4];//满意值 组别
	PII pri[4];
	int nxt[4];//nxt[i] 第i组下位是哪个组
	void sort_INFM()
	{
		sort(a,a+3,cmp);
	}
};
bool cmp_INFM(JOIN_INFM &x,JOIN_INFM &y)
{
	return x.a[0].first>y.a[0].first;
}
JOIN_INFM per[N];
priority_queue<PII> group[4];//降序
int change_val(int now,int to_group)
{
//	cout<<per[now].nxt[to_group]<<' '<<to_group<<'\n';
	return (per[now].pri[per[now].nxt[to_group] ].first- per[now].pri[to_group].first);
	//		下位贡献									上位贡献
	//下位替代产生的变化
}
//void ins(int now,int to_group)
//{
//	if(int(group[to_group].size())<n/2)//塞得下
//	{
//		group[to_group].push({change_val(now,to_group),now});
//	}
//	else
//	{
//		PII ra=group[to_group].top();
//		int oppoent_change_val=ra.first,oppoent=ra.second;
////		cout<<now<<' '<<oppoent<<'\n';
////		cout<<change_val(now,to_group)<<' '<<oppoent_change_val<<'\n';
//		if(change_val(now,to_group)<oppoent_change_val)//大于
//		{
//			//对手走
//			group[to_group].pop();
//			group[to_group].push({change_val(now,to_group),now});
//			
//			ins(oppoent,per[oppoent].nxt[to_group]);
//		}
//		else
//		{
//			//我走
//			ins(now,per[now].nxt[to_group]);
//		}
//	}
//}
void solve(int tcase)
{
	//不用ll
	//贪心地去选当前贡献最大的
	//如果塞的下 恭喜发财
	//设 下位贡献-当前贡献 为 转移值
	//显然转移时ans+=转移值
	//如果塞不下 考虑当前队伍中转移值最大的那个人(设为对手1)(肯定有啊你都塞不下了)
	//如果对手转移值小于当前转移值
	//那么 当前这个人去找下一个组
	//否则 对手出列去找下一个组
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			int saf_now;
			cin>>saf_now;
			per[i].a[j]={saf_now,j};
			per[i].pri[j]={saf_now,j};
		}
		per[i].sort_INFM();
		for(int j=0;j<3;j++)
		{
			per[i].nxt[per[i].a[j].second]=per[i].a[(j+1)%3].second;
		}
	}//将人的满意值排序
	sort(per+1,per+n+1,cmp_INFM);
	
	for(int i=1;i<=n;i++)
	{//对per[i]处理
		int to_group=per[i].a[0].second;
		group[to_group].push({change_val(i,to_group),i});
//		for(int j=0;j<3;j++)
//		{
//			cout<<per[i].a[j].first<<"GP"<<per[i].a[j].second<<' ';
//		}cout<<'\n';
	}
	for(int rx=0;rx<=6;rx++)
	{
		for(int j=0;j<3;j++)
		{
			while(int(group[j].size())>n/2)
			{
				PII ra=group[j].top();
				group[j].pop();
				
				int now=ra.second;
				int to_group=per[now].nxt[j];
				group[to_group].push({change_val(now,to_group),now});
			}
		}
	}
	int ans=0;
	for(int j=0;j<3;j++)
	{
		while(group[j].size())
		{
			int now=group[j].top().second;
//			cout<<now<<' ';
			group[j].pop();
			
			ans+=per[now].pri[j].first;
//			for(int i=0;i<3;i++)
//			{
//				if(per[now].a[i].second==j)
//				{
//					ans+=per[now].a[i].first;
//					break;
//				}
//			}
		}
//		cout<<'\n';
	}
	cout<<ans<<'\n';
//	两个小时，T1结束了。
//	可不知？
//	旧日尚未尽力共挽手到未来 今天终于分开未说出应不应该
//	怎么梦境都不再？
}
int main(	)
{
	fopen("club");
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		solve(i);
	}
	return 0;
}