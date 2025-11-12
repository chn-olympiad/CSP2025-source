#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 1e5+50;
int a[N];
int cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt++;
	}
	if (cnt % 2 == 0)
		cout << cnt;
	else
		cout << cnt - 1;
}
//ps:以下言论没有任何诋毁组委的不良言论，组委会不要禁我赛。。
//aoeiwvbpmfdtnlgkhjqxzhichishirizicisiangengyingwengyun
//监考老师你别看了我害怕。。///我想回家。。我想打三角洲。。组委会下次能不能给我们
//这些菜人提供个提前交卷的通道啊。。太煎熬了。。我现在还要在这熬76分钟。。感觉快
//能写一本小说了。。给大家来个Wink吧，这事好久不做了，啊~
//作业：语文：群里发的题：唐雎不辱使命写完  数学：月末综合测试卷二写完
//英语：2a,2b,2c,self check2完成  道法：群里发的卷纸  物理：不知道。。
//化学：第二还是第三学时写完吧  历史：写题  好嘛，睡前来上这么一段天塌了。。
//桃花源记 陶渊明   ：：晋太元中，武陵人捕鱼为业，缘溪行，忘路之远近，
//忽逢桃花林。桃花潭水深千尺不及汪伦送我情？不会背了。。哦又会了，夹岸数百步，
//中无杂树，芳草鲜美，落英缤纷。渔人甚异之，复前行，欲穷其林。林尽水源，
//便得一山，山有小口，仿佛若有光，便舍船，从口入。初极狭，才通人，复行数十步，
//豁然开朗，土地平旷，屋舍俨然，有良田美竹桑竹之属，阡陌交通，鸡犬相闻。黄发垂髫，
//便怡然自乐。完蛋真不会背了。。
//狼 蒲松龄 一屠晚归，但中揉进，只有生故。途中两狼，赘行深渊。屠拒，头一股，伊朗的估值，伊朗仍从。
//复透支，后浪之二前浪幼稚。京东方卡萨活佛的撒谎方式。。。不会背了。。我真不想学语文课。。
//dog wolf fruit inexpensive money dollor US UA NASA astronaut recort
//fly plane kill man woman player competitor basket football ball baseball
//bat ping-pong small big large high tall thin thing fat weight kilometer
//monday tuesday wednesday thursday friday saturday sunday january
//february march april june july august september october november december
//laugh happy happiness sad bad great more less wonderful fantastic
//kite
//再给我两分钟~让我把记忆结成冰，别融化了眼泪你妆都花了，要我怎么记得，
//记得你要我忘了吧，记得你要我忘了吧，你说你会哭，不是因为在乎~