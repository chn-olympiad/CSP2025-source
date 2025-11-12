#include <bits/stdc++.h>
using namespace std;
int n,k,arr[500005],sum[500005],ans;
bool flag[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	int xb=1;
	for(int len = 1; len <= n; len++) {
		for(int i = 1; i+len-1 <= n; i++) {
			int j = i+len-1,sum=0;
			for(int x = i; x <= j; x++)
				sum^=arr[x];
			if(sum==k) {
				if(flag[i]==false&&flag[j]==false) {
					for(int x = i; x <= j; x++)
						flag[x]=true;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
//前一日哦为给对方vzx以后就覆盖也而我却给组v先从IP热昂贵的发哈对方是个合法的时间誉为v从造型 
//过去热舞阿凡达所以v现处于一个法师攻防亚特法律阿斯顿发花痴啊而已的发射点v办法是不懂法二哥 
//规划局而我更认为jerk千万个然后去问别人去v个人雅夫卡是个好地方gay怪不得就是看个按规范好的 
//风格恢复很多很多黄毒蛾吧自行车v中国功夫卡江苏凤凰大厦弗拉官员的本本背负着发哈史蒂夫卡河 
//和事件的看法好烦好烦好烦成本v有合适的回复啊是否不然别人让你加入基督教和规范去微软推哦怕时 
// 青蛙大西安的夫人通过吃饱混屡次哦哦普及奇葩了怎么我是看校内多久才能乳房和不同与提高    
//去问人体影片时代法国红酒看来自行车不能啊欸偶
//去啊哇饿啊让她呀u爱奥阿帕拉卡机啊哈噶哈吉奥卡拉咋写啊擦v啊巴拿马 
