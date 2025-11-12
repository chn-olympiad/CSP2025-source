#include<bits/stdc++.h>
using namespace std;
#define IO cin.tie(0);cout.tie(0);

const int INF = 0x3f3f3f3f;
const int N = 3e4+10;

struct part{
	int val=0;
	int who=0;
	int want=0;
};

int n;
bool vis[N];
part in[N];
pair<int,int> club[4];

int main(){
	IO;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=3; j++){
				int val;
				cin>>val;
				in[i*3-j+1].val = val;
				in[i*3-j+1].who = i;
				in[i*3-j+1].want = j;
			}
		}
		sort(in+1, in+3*n+1, [](part a, part b){
			return a.val > b.val;
			});
		
		for (int i = 1; i<=3*n; i++){
			if (vis[in[i].who] == 0 && club[in[i].want].second < n/2){
				vis[in[i].who] = 1;
				club[in[i].want].first += in[i].val;
				club[in[i].want].second += 1;
			}
		}
		
		cout << club[1].first + club[2].first + club[3].first << '\n';
		// clear
		club[1].first = club[1].second = 0;
		club[2].first = club[2].second = 0;
		club[3].first = club[3].second = 0;
		for (int i = 1; i<=3*n; i++) vis[i] = 0;
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
