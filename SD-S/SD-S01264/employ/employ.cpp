#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, a[100005], k, b[100005];
    cin >> n >> k;
    string s;
    cin >> s;
    int n2 = n; 
    for (int i = 1; i <= n; i++) 
    {
    	cin >> a[i];
    	b[i] = i;
    	if (a[i] == 0) n2 --;
	}
	int ans = 0;
	int sum = 0;
	do{
	    sum = 0;
	    for (int i = 0; i < n; i ++) 
	    {
	    	if (s[i] == '0') sum ++;
	    	else if (a[b[i + 1]] <= sum) sum ++;
	    //	cout << sum << " ";
	    } 
	    if (sum <= n - k) ans ++;
	}while(next_permutation(b + 1, b + n + 1));
	cout << ans << endl;
	return 0;
}
/* 
整什么活好呢

哦对了：
2025 CCF 非专业级软件能力认证
CSP-J/S 2025 第二轮认证
提高级
时间：2025 年11 月1日14:30 ～ 18:30
题目名称
社团招新
道路修复
谐音替换
题目类型
传统型
传统型
传统型
员工招聘
传统型
目录
club
 road
 replace
 employ
可执行文件名 club
 road
 replace
 employ
输入文件名
club.in
 road.in
 replace.in
 employ.in
输出文件名
club.out
 road.out
 replace.out employ.out
每个测试点时限 1.0秒
1.0 秒
1.0 秒
1.0 秒
内存限制
512 MiB
 512 MiB
 2048 MiB
 512 MiB
测试点数目
20
 25
 20
 25
测试点是否等分 是
是
是
提交源程序文件名
对于C++ 语言 club.cpp
是
road.cpp
编译选项
对于C++ 语言
replace.cpp employ.cpp‐O2‐std=c++14‐static
 .
注.意 .事 .项（ .请 .仔 .细 .阅 .读）
1. 文件名（程序名和输入输出文件名）必须使用英文小写。
2. main 函数的返回值类型必须是int，程序正常结束时的返回值必须是0。
3. 若无特殊说明，结果的比较方式为全文比较（过滤行末空格及文末换行）。
4. 选手提交的程序源文件大小不得超过100KiB。
5. 提交的程序源文件的放置位置请参考各省的具体要求。
6. 程序可使用的栈空间内存限制与题目的内存限制一致。
7. 禁止在源代码中改变编译器参数（如使用#pragma命令），禁止使用系统结构相
关指令（如内联汇编）或其他可能造成不公平的方法。
8. 因违反上述规定而出现的问题，申诉时一律不予受理。
9. 只提供Linux 格式附加样例文件。
10. 全国统一评测时采用的机器配置为：Intel Core Ultra 9 285K CPU @ 3.70 GHz
（关闭睿频与能效核），内存96GB。上述时限以此配置为准。
11. 评测在当前最新公布的NOILinux 下进行，各语言的编译器版本以此为准。
 
 
 
       CCCCCCCCC     CCCCCCCCCC      FFFFFFFFFFF 
	   C             C               F
	   C             C               F        
	   C             C               F
	   C             C               FFFFFFFFFFF
	   C             C               F
	   C             C               F       
	   CCCCCCCCC     CCCCCCCCCC      F
*/ 
