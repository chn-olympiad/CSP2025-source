#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 10;

const long long B = 133331;

bool m1;

long long n, q;

string s, a, b;

map<pair<unsigned long long,unsigned long long>,long long > mp; 

void read(){
	cin >> n >> q;
	for(long long i = 1;i <= n; i++){
		cin >> s;
		unsigned long long x = 0, y = 0;
		for(char c : s){
			x *= B;
			x += c;
		}
		cin >> s;
		for(char c : s){
			y *= B;
			y += c;
		}
		mp[{x,y}]++;
	}
}

void init(){

}

unsigned long long ha[N][2], power[N];

void compute(){
	power[0] = 1;
	for(long long i = 1;i <= N-1; i++) power[i] = power[i-1] * B;
	for(long long i = 1;i <= q; i++){
		cin >> a >> b;
		long long l = a.size() - 1, r = 0;
		for(long long j = 0;j < a.size(); j++){
			if(a[j] != b[j]){
				l = j;
				break;
			}
		}
		for(long long j = a.size() - 1;j >= 0; j--){
			if(a[j] != b[j]){
				r = j;
				break;
			}
		}
		for(long long j = 0;j < a.size(); j++){
			ha[j][0] = (j>=1?ha[j-1][0]:0)*B+a[j];
			ha[j][1] = (j>=1?ha[j-1][1]:0)*B+b[j];
		}
		long long ans = 0;
		if(l == a.size() - 1 && r == 0){
			for(long long x = 0;x < a.size(); x++){
				for(long long y = x;y < a.size(); y++){
					ans += mp[{ha[y][0]-(x>0?ha[x-1][0]:0)*power[y-x+1],ha[y][1]-(x>0?ha[x-1][1]:0)*power[y-x+1]}];
				}
			}
		}
		else{
			for(long long x = 0;x <= l; x++){
				for(long long y = r;y < a.size(); y++){
					ans += mp[{ha[y][0]-(x>0?ha[x-1][0]:0)*power[y-x+1],ha[y][1]-(x>0?ha[x-1][1]:0)*power[y-x+1]}];
				}
			}
		}
		cout << ans << '\n';
	}
}

void clear(){

}

void run(){
	read();
	init();
	compute();
	clear();
}

bool m2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	run();
	return 0;
}

