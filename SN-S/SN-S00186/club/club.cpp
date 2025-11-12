#include<bits/stdc++.h>
#define N 100005
using namespace std;

int T, n;
struct edge{
	int a, b, c;
}oqo[N];

bool cmp(edge x, edge y){
	if(x.a > y.a) return x.a > y.a;
	else return x.b > y.b;
}

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++)
			cin >> oqo[i].a >> oqo[i].b >> oqo[i].c;
		sort(oqo+1, oqo+1+n, cmp);
		
		int sum = 0;
		for(int i = 1;i <= n/2;i++)
			sum += oqo[i].a;
		
		cout << sum << "\n";
	}
	
	return 0;
}
