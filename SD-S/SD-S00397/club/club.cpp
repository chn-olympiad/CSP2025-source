#include <cstdio>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;
#define LL long long
#define x first
#define y second

typedef pair<int,char> PB;
const int N = 200010;

PB in[N][3];

int read(){
	int out = 0;
	char in = getchar();
	while (!isdigit(in))
		in = getchar();
	while (isdigit(in)){
		out = out * 10 + (in - '0');
		in = getchar();
	}
	return out;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T = read();
	
	while (T--){
		int n = read();
		int m = n / 2;
		LL sum = 0;
		priority_queue<int,vector<int>,greater<int> > d[3];
		for (int i = 0;i < n;i++){
			in[i][0] = {read(),0},in[i][1] = {read(),1},in[i][2] = {read(),2};
			sort(in[i],in[i] + 3,greater<PB>());
		}
		
		for (int i = 0;i < n;i++){
			int v = in[i][0].x;
			char p = in[i][0].y;
			if (d[p].size() < m){
				sum += v;
				d[p].push({v - in[i][1].x});
			}else{
				if (v - in[i][1].x > d[p].top()){
					sum -= d[p].top();
					sum += v;
					d[p].push(v - in[i][1].x);
					d[p].pop();
				}else{
					sum += in[i][1].x;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
