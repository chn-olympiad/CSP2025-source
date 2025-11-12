//J组咋这么简单啊，1hAK了干啥啊，我记得好像不让提前离场来着 
//还不如不来在家玩神秘五字游戏呢，3h应该够我推完巡线了吧 
//神秘四字中间带个星游戏基本感情线第8章就定型了而这个感觉慢一点 
//我是不是应该找点剧情更有深意的推 
//ciallo~(∠>ω< )⌒☆
//问为啥打的不正宗是因为 dev 显示不了片假名中间点就拿大于号替代了 
//哦还有上圆弧也显示不了，但这个作为几何学基本符号的可以 
//我们发现 0d00 是这个题的一个coner case，或许可以作为 hack 
//freopen ←据说这样可以引来收集行为大赏的人 
//freopen //	freopen("number.out","r",stdin);
//luogu 关注 UKE_Automation 谢谢喵 
//我是不是应该打点拍而不是在这里发表感想 
//好的拍打完了，吓死了，T1忘判非数字，T4漏加取模 
//然后又到了喜闻乐见的罚坐环节 
//surf真好玩，蜘蛛纸牌真好玩 
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
char s[1001000];
int st[10],n;
string main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]<'0'||s[i]>'9') continue;
		st[s[i]-'0']++;
	}
	int flag=0;
	for(int i=9;i;i--){
		while(st[i]--){
			cout<<i;
			flag=1;
		}
	}
	if(flag){
		while(st[0]--){
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	cout<<'\n';
	return "J组就是试机111";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB()<<'\n';
}
