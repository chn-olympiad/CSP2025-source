#include <iostream>
#include <algorithm>
using namespace std;

struct Stu{
	int id;
	int sc;
} ar[110];
int g[20][20];

bool cmp(Stu a, Stu b){
	return a.sc > b.sc;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin>>n>>m;
	
	int al = n*m;
	
	for(int i=1; i<=al; i++){
		cin>>ar[i].sc;
		ar[i].id = i;
	}
	
	sort(ar+1, ar+al+1, cmp);
	
	int cnt = 0;
	int x=0, y=1;
	while(true){
		while(x < n){
			x ++;
			cnt ++;
//			cout<<x<<" "<<y<<" "<<cnt<<"\n";
			if(ar[cnt].id == 1){
				cout<<y<<" "<<x<<endl;
				return 0;
			}
		}
		
		y ++;
		cnt ++;
//		cout<<x<<" "<<y<<" "<<cnt<<"\n";
		if(ar[cnt].id == 1){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		
		while(x > 1){
			x --;
			cnt ++;
//			cout<<x<<" "<<y<<" "<<cnt<<"\n";
			if(ar[cnt].id == 1){
				cout<<y<<" "<<x<<endl;
				return 0;
			}
		}
		
		y ++;
		cnt ++;
//		cout<<x<<" "<<y<<" "<<cnt<<"\n";
		if(ar[cnt].id == 1){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		
	}
	
	return 0;
}

/*

写不行了，不写日志了
这个键盘的 'D' 键需要使劲敲才能输入

数据范围就这点？模拟

9:38:08 完成

O(∩_∩)O谢谢你，CCF！
前两题很简单！

*/