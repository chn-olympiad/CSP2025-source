#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll n,a[maxn][3],T,mx[maxn],num1[maxn],num2[maxn],num3[maxn],f[maxn][3];
bool flag[maxn][3];
void slove(){
	ll n;
	cin >> n;
	ll ans = n / 2;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++) cin >>a[i][j];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){                   //每行找最大 
			mx[i] = max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1] == a[i][2]){
				f[i][2] = a[i][2];
				num1[i] = a[i][1];
			}
			else if(a[i][2] == a[i][3]){
				f[i][3] = a[i][3];
				num2[i] = a[i][2];
			}
			else if(a[i][3] == a[i][1]){
				f[i][1] = a[i][1];
				num3[i] = a[i][3];
			}
			else if(mx[i] == a[i][1]) num1 = a[i][1];
			else if(mx[i] == a[i][2]) num2 = a[i][2];
			else if(mx[i] == a[i][3]) num3 = a[i][3];
		}
	}
	ll n1 = num1.size();
	ll n2 = num2.size();
	ll n3 = num3.size();
	if(n3 > ans){
		for(int i = 1;i <= n3;i++){               //有东西移走 ,好像f不要也行
			if(f[i][1] != 0 || f[i][2]] != 0){
				if(n1 + 1 <= ans) num1[i] = f[i][1]；
				else if(n2 + 1 <= ans) num2[i] = f[i][2];
			}
		}
	}
	n1 = num1.size();
	n2 = num2.size();
	n3 = num3.size();
	if(n2 > ans){
		for(int i = 1;i <= n2;i++){              
			if(f[i][1] != 0 || f[i][3]] != 0){
				if(n1 + 1 <= ans) num1[i] = f[i][1]；
				else if(n3 + 1 <= ans) num3[i] = f[i][3];
			}
		}
	}
	n1 = num1.size();
	n2 = num2.size();
	n3 = num3.size();
	if(n1 > ans){
		for(int i = 1;i <= n1;i++){              
			if(f[i][3] != 0 || f[i][2]] != 0){
				if(n3 + 1 <= ans) num3[i] = f[i][3]；
				else if(n2 + 1 <= ans) num2[i] = f[i][2];
			}
		}
	}
	n1 = num1.size();
	n2 = num2.size();
	n3 = num3.size();\
	ll ans1,ans2,ans3;
	for(int = 1;i <= n1;i++) ans1 += num1[i];
	for(int = 1;i <= n2;i++) ans2 += num2[i];
	for(int = 1;i <= n2;i++) ans2 += num3[i];
	ll ans_z = ans1 + ans2 + ans3;
	cout << ans_z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T --){
		slove(); 
	}
} 
