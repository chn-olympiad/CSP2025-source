#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct A{
	int u,v,w;
}e[1000010];
int a[15][10010],c[15],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		ans+=e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<ans;
	return 0;
}

/*
dalesansiniandexingjingshenmechengjidoumeidachulai
jinnianyijinggaoerle zhechangcspdawangujijiumeiyouxiacile
NOIPgujishimeixile gaolelsansinianxingjingjiuzheyangjieshule
tingbuganxinde diyitidoumeiyouAdiao
mingnianjiugaosanle yinggaishibuhuizaidaxinjingle 
zheshiwodiyicizaisaichangshangdazhezhongzhushi
woyeshizaibuzhidaogaizenmebanle
haishibawodewenhuakeduhaoba
yaozhuanxinduwenhuakele
zhejinianxinjingfensanlewotingduojinglidehaihaowenhuakemeiyoulaxiahenduo
buranzhenjiuzhulandashuiyichangkongle
zuihouhaishiyaohuiguiwenhuakede
buzhidaowenhuakenengbunengzaihaoyidian
nengbunengchunluofenshangzijixiangshangdedaxue
*/