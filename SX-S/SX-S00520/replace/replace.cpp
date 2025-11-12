#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=5e6+5;
int n,q,num[N],l[M],r[M];
char input[2][M];
struct Idk
{
	int k,l;
}cnt[N];
bool cmp(Idk X,Idk Y)
{
	if(X.k!=Y.k) return X.k<Y.k;
	else return X.l<Y.l;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>input[0]>>input[1];
		for(int j=0;j<=strlen(input[0]);j++)
			if(input[0][j]=='b') 
			{
				for(int k=0;k<=strlen(input[1]);k++)
					if(input[0][k]=='b')
					{
						cnt[i].k=abs(j-k);
						cnt[i].l=strlen(input[1]);
						break;
					}
				break;
			}
	}
	sort(cnt+1,cnt+1+n,cmp);
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>input[0]>>input[1];
		for(int j=0;j<=strlen(input[0]);j++)
			if(input[0][j]=='b') 
			{
				for(int k=0;k<=strlen(input[1]);k++)
					if(input[0][k]=='b')
					{
						num[i]=abs(j-k);
						break;
					}
				break;
			}
		for(int i=1;i<=n;i++)
		{
			if(cnt[i].k==num[i])
			{
				if(cnt[i].l>strlen[input[1]]) break;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//T3-replace
//以防你不知道，今天是明日方舟6.5周年庆
//以防你不知道，我80抽vvan+银灰+初雪 卡池毕业了
//我愿以两年不出ew的代价换我这次CSP-S不会爆0
//再给我歪两个芜拉
//呜呜呜我的芜拉现在还没满潜
//只要YJ给我满潜芜拉，就算是100抽给我出174+ew+迷迭香+eew+满潜银灰初雪我也愿意啊TAT
//还有就是   《四个汉字 : 三个字》就要我也不知道几测了
//			   空洞骑士 : 丝之歌（划掉）
//我现在就要玩 明日方舟 : 终末地 ！