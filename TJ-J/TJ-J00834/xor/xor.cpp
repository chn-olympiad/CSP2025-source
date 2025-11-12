#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
bool visited[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	vector<int> a(n+5);
	vector<int> b(n+5);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] == k){
			ans++;
			visited[i] = true;
		}
	}
	for(int c = n;c>0;c--){
		for(int i = 1;i < c;i++){
			b[i-1] = a[i-1] xor a[i];
			if(b[i-1] == k){
				if(k != a[i-1] and k != a[i] and !visited[i-1]){
					ans++;
				}
				visited[i-1] = true;
			}
		}
		/*
		cout << endl;
		for(int i = 0;i < c;i++) cout << a[i] << ' ';
		cout << endl;
		for(int i = 0;i < c-1;i++) cout << b[i] << ' ';
		cout << endl;
		for(int i = 0;i < c-1;i++) cout << visited[i] << ' ';
		*/
		for(int i = 0;i < c-1;i++){
			if(!visited[i]){
				visited[i] = visited[i+1];
				visited[i+1] = false;
			}
		}
		a = b;
	}
	cout << ans << endl;
}

