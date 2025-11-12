#include <bits/stdc++.h>
using namespace std;
map <string, string> mp;
int main()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, q, ans = 0;
    cin >> n >> q;
    string a, b;
    for (int i = 1; i <= n; i ++)
    {
    	cin >> a >> b;
    	mp[a] = b;
	}
	string xa, ya, xb, yb, za, zb;
	while (q --)
	{
		ans = 0;
		cin >> a >> b;
		a = " " + a;
		b = " " + b;
		if (a.size() != b.size())
		{
			cout << 0 << endl;
			continue;
		}
		for (int l = 1; l < a.size(); l ++)
		{
			for (int r = l; r < a.size(); r ++){
				xa = a.substr(1, l - 1);
				xb = b.substr(1, l - 1);
				ya = a.substr(l, r - l + 1);
				yb = b.substr(l, r - l + 1);
				za = a.substr(r + 1, a.size() - r - 1);
				zb = b.substr(r + 1, b.size() - r - 1);
				if (xa == xb && za == zb && mp[ya] == yb) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//sto ccf rp++ #include<bits\stdc++.h>（诈骗）

/*

《关山酒》（梦泪神曲） 

我自关山点酒 千秋皆入喉

更有飞雪灼与风云某

我是千里故人 青山应白首

年少犹借银枪逞风流 

几载风雪卷刃 朔风同孤昼

瞧得乱世 一般嶙峋瘦

塞外硝烟未断 黄云遍地愁

侥幸红梅久 不曾下枝头

长烟入怀 潦草做运筹

踏破飞沙拔剑斩仇寇

残阳暮火 春风上重楼

乱世烽火不近长安囚 

我自关山点酒 千秋皆入喉

更有飞雪灼与风云某

我是千里故人 青山应白首

年少犹借银枪逞风流 

我曾长安走马 十街任斗酒 

惊梦照烽火 今宵试新鍪

倘若魂断沙场 不见失地收 

谁共谁不朽 金戈亦染锈 

天命轻狂 应似孤鸿游

向人世间尽一副鬼谋

纵意而歌 玉怀斟北斗

河山万里 愿与君同守

我自关山点酒 千秋皆入喉

更有飞雪灼与风云某

我是千里故人 青山应白首

年少犹借银枪逞风流  
*/ 
