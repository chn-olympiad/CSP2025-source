#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int k;k<t;k++){
		int n = 0,ans=0;
		cin >> n;
		for(int i =0;i<n;i++)
		{
			int o=0,p=0,q=0;
			cin >> o;
			cin >> p;
			cin >> q;
			ans += max(max(o,p),q);
		}
		cout << ans << "\n";
	}
	//这比去年的第一题难好多，CCF你想干什么，把CSP-S第二轮当NOI国赛出吗??????????? 
	//我这么吉利的准考证号，为何不把题出简单一点，让我写出来一整道题也好啊555 
	return 0;
}

