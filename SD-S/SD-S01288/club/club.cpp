#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;

const ll m = 3;

ll t,n,num = 0;

ll A[N][5];

ll book[N];

void lps(ll deep,ll res){
	if(deep > n){
		num = max(num,res);//取最大值  
		return ;
	}
	for(ll x = 1;x <= m;x ++){
		if(book[x] >= n / 2) continue;
		book[x] ++;
		lps(deep + 1,res + A[deep][x]);//每个都拿试试 
		book[x] --;
	}
	return ;
}

// Ren5Jie4Di4Ling5%

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n;
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				cin >> A[i][j];
			}
		}
		lps(1,0);
		cout << num;
		cout << endl;
		num = 0; 
		memset(book,0,sizeof book);
	}
	return 0;
}
