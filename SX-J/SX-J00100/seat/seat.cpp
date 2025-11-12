#include<bits/stdc++.h>
using namespace std;

int mark[103];
int l, h;
int n, m;

bool cmp(int x, int y){
	return x > y;
}

void Solve(int loc){
	cout << loc / n + 1 << " ";
	bool exchange = false; //自下而上
	if((loc / n + 1) % 2) exchange = true; //自上而下
	int t = loc / n;
	t = t * n;
	if(exchange){
		cout << loc + 1 - t;
	}else if(!exchange){
		cout << n - (loc + 1 - t) + 1;
	}
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int k = n * m;
	for(int i = 0; i < k; i++){
		cin >> mark[i];
	}

	int f = mark[0];

	sort(mark, mark + k, cmp);

	int mid, l = 0, r = k - 1;
	while(1){
		mid = (r - l) / 2 + l;
		if(mark[mid] == f){
			Solve(mid);
			break;
		} else if(mark[mid] > f){
			l = mid + 1;
		} else if(mark[mid] < f){
			r = mid - 1;
		}
	}
	return 0;
}