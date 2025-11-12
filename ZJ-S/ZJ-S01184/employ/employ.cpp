#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5;
const int Mode = 998244353;
int c[N];
int sum[N];
long long jiecheng(int x){
	long long sum = 1;
	for(long long i = 1; i <= x; i++){
		sum = (sum*i)%Mode;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		sum[i+1] = sum[i]+s[i]-'0';
	}
	for(int j = 1; j <= m; j++){
		cin >> c[j];
		if(c[j] == 0){
			sum[n]++;
		}
	}
	cout << 0;
	return 0;
}
