//Author:ZhuHua14(luogu)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 505;
const int MOD = 998244353;
int n,m,c[MAXN];
bool diffi[MAXN];
string s;

//10pts 17£º11 
bool check(int a[]){
	int cnt = 0,lsc = 0;
	for(int i = 1; i <= n; i++){
		if(diffi[i] == 0 || c[a[i]] <= lsc){
			lsc++;
		}
		else{
			cnt++;
		}
		////cerr << i << ' '<< a[i] <<' ' << c[a[i]] << ' '<< diffi[i] << ' ' << lsc << ' ' << cnt << '\n'; 
	}
	if(cnt >= m) return 1;
	else return 0;
}


void print(int a[],int len){
	for(int i = 1; i <= len; i++){
		//cerr << a[i] << ' ';
	}
}

void solve1(){
	int a[MAXN];
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
	int ans = 0;
	do{
		//print(a,n);
		//cerr << '\n';
		if(check(a)){
			ans++;
			ans %= MOD;
		}
	}while(next_permutation(a + 1,a + 1 + n));
	cout << ans << '\n';
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ2.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	int len = s.size();
	for(int i = 0; i < len; i++){
		diffi[i + 1] = s[i] - '0';	
	}
	if(n <= 10) solve1();
	return 0;
}

