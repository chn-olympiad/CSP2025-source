#include <iostream>
#include <cstdio>
#include <string>

using namespace std; 

#define N 200005

int n, q;

string s1[N], s2[N], t1[N], t2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i++) cin >> t1[i] >> t2[i];
	for (int i = 1; i <= q; i++) {
		if (t1[i].size() != t2[i].size()) {
			cout << 0 << endl;
			continue;
		}
		int x = 0, m = 0, ans = 0, p, a;
		for (int j = 0; t1[i][j] != 'b'; j++) x++;
		for (int j = 0; t2[i][j] != 'b'; j++) m++;
		for (int j = 1; j <= n; j++) {
			p = 0, a = 0;
			for (int k = 0; s1[j][k] != 'b'; k++) p++;
			for (int k = 0; s2[j][k] != 'b'; k++) a++;
			if (x + a == p + m) {
				ans++;
			}
		} 
		cout << ans << endl;
	}
	return 0;
}

/*
代码迷惑行为大赏 从夯到拉 5个级别 
1. freopen出错：虽然错误非常低级，但是是用自己的分换来的，付出了很大代价。所以给到NPC
2. 乱码大师：没有任何技术含量可言，不过需要一定耐心。给到NPC
3. 暴戾代码：容易被禁赛三年。直接给到拉
4. 考场游记：对于Linux虚拟机环境下的考生，在自己的IDE中是只能输入英文的。因此想要写出一篇
   较为完整的游记，还是很考验英语功底的。不过由于烂大街了，所以只能给到大众化
5. 长难程序：起手就是几百行的程序，大部分都是if, else，给人一种模仿初学者的行为。由于
   这些代码有相当一部分是有一定逻辑而且能在题目上拿到分的，所以给到大众化
6. O(1)战神：数组连接答案，打表代替思考。这是一种如果能利用好就非常NB的算法，对于一些
   有耐心的人打表获得的分甚至比正常写都要高，更有甚者打表打着打着写出了正解，所以我
   对他们是比较敬佩的。给到顶尖。
7. 游戏乱入：例如拿游戏角色命名变量，提及有关游戏的内容。这其中以Genshin Impact Game和
   Phigros居多。综合给到大众化。
8. 宁为玉碎，不为瓦全：while (1); 即可完成，没有什么含金量。给到NPC
9. 神秘数字：逸一时，误一世，出场频率非常之高，而且经久不衰，这其中肯定有他的魅力。直接
   给到顶尖。
10.rp++：据说在程序每一行注释写上rp++有助于提高程序正确率，必须夯。
11.题目复述：救赎之道，就在其中。比较考验耐心，给到大众化。
12.Never gonna give you up 
*/
