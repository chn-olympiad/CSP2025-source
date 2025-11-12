#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int R;
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	R = a[0];
	sort(a,a + n * m);
	queue<int> q;
	for(int i = 0;i < n * m;i++){
		q.push(a[i]);
	}
	int c = 1,r = 1;
	bool flagc = true;
	for(int i = 0;i < n * m;i++){
		if(flagc) c++;
		else c--;
		if(flagc && c > n){
			c = n;
			flagc = !flagc;
			r++;
		}
		if(!flagc && c < 1){
			c = 1;
			flagc = !flagc;
			r++;
		}
		if(q.front() == R){
			cout << c << " " << r;
			return 0;
		}
		q.pop();
	}
	return 0;
}
