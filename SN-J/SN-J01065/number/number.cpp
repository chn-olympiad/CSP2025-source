//SN-J01065 郭子羽 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
string s; int n,cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		int x = s[i] - '0';
		if(x < 0 || x > 9) continue;
		cnt[x]++;
	} 
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= cnt[i];j++){
			cout << i;
		}
	}
	return 0;
}//复杂度O(n)，预计100
/*
C:\Users\Administrator>fc D:\SN-J01065\number\number4.ans D:\SN-J01065\number\number4.out
正在比较文件 D:\SN-J01065\NUMBER\number4.ans 和 D:\SN-J01065\NUMBER\NUMBER4.OUT
FC: 找不到差异
*/
