#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int a[N][10];
int sta[N];
int mbct[10];
int ans;
int n;

void dfs(int x){
	if(x == n){
		int t=0;
		for(int i=0; i<n; i++){
			t += a[i][sta[i]];
		}
		ans = max(ans, t);
		return;
	}
	
	for(int i=1; i<=3; i++){
		if(mbct[i] == n/2) continue;
		mbct[i] ++;
		sta[x] = i;
		dfs(x+1);
		mbct[i] --;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin>>t;
	
	while(t --){
		memset(sta, 0, sizeof sta);
		memset(mbct, 0, sizeof mbct);
		
		cin>>n;
		
		for(int i=0; i<n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		ans = -1;
		dfs(0);
		
		cout<<ans<<endl;
	}

	return 0;
}

/*

有 n 个物品，3 个背包
第 i 个物品装进第 j 个背包里价值为a[i][j]
每个背包的容积为 n/2
每个物品体积为 1
求 3 个背包最大价值和

或者此策略：
让每个员工去最高满意度的部门
哪个部门超了
就选这个部门中对本部门满意度最低的进入第二满意的部门
进入第二满意后还超
就选这个部门中对本部门满意度最低的进入第三满意的部门

还是第一个听着对一点
怎么写啊好烦啊
已经开考快一个半小时了

首先遍历员工
对于每个员工
遍历三个部门
怎么好像dfs
要不先写dfs暴力解法

暴力写了
但是暴力只能拿20分

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int a[N][10];
int sta[N];
int mbct[10];
int ans;
int n;

void dfs(int x){
	if(x == n){
		int t=0;
		for(int i=0; i<n; i++){
			t += a[i][sta[i]];
		}
		ans = max(ans, t);
		return;
	}
	
	for(int i=1; i<=3; i++){
		if(mbct[i] == n/2) continue;
		mbct[i] ++;
		sta[x] = i;
		dfs(x+1);
		mbct[i] --;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin>>t;
	
	while(t --){
		memset(sta, 0, sizeof sta);
		memset(mbct, 0, sizeof mbct);
		
		cin>>n;
		
		for(int i=0; i<n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		ans = -1;
		dfs(0);
		
		cout<<ans<<endl;
	}

	return 0;
}
```

16:42 我现在脑子里一直有两个声音
	  一个声音说你现在很累，快歇歇，别写了
	  一个声音说不行，至少拿到100分。题都分析清楚了，怎么能不会写？继续调！
	  然后我就继续写
	  然后又不会写了
	  while(true){
	    写代码;
	    不会写了;
		心中矛盾;
	  }
	  
16:52 我刚刚试着写正解（应该是dp吧？）
	  写dp写着写着写成模拟了
      先就这样写吧
      不管了
      
17:00 我真想直接躺平了
	  			不写了
	  小样例一直过不了
	  反正这次参加S级就是重在参与
	  					 没想拿成绩
	  今年的T1很难吗？
	  会不会和去年T2对于我一样
	  不会dfs
	  调不对模拟
	  
	  去年的结果是想拿10分部分分
	  然后打表
	  然后打错了（？）
	  0分
	  
	  今年暴力部分分肯定没问题
	  但是我现在很想知道这题的难度评级
	  普及- 普及/提高- 普及+/提高 提高+/省选-
	  好决定放不放弃拿满分

17:05 中午12:45回到家
	      13:25吃完饭
      收拾收拾，玩一玩
      还没来得及躺下
      就又该出发了
      现在好累...
      
17:08 我决定了
	  就打暴力
	  拿20分
	  至少证明我来过
	  		  我也奋斗过
	  生成校验，睡觉吧
*/
