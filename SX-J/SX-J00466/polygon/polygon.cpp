#include <iostream>
using namespace std;

const int MOD = 998244353;
int a[5010];
bool ar[5010];
int n;
int ans;

bool myWork1(){
	int cnt = 0;
	int sum = 0;
	int maxi = -1;
	for(int i=0; i<n; i++){
		if(ar[i]){
			cnt ++;
			maxi = max(maxi, a[i]);
			sum += a[i];
		}
	}
	if(sum > 2*maxi && cnt >= 3) {
//		cout<<"选择第 ";
//		for(int i=l; i<=r; i++) cout<<i+1<<" ";
//		cout<<" 根小木棍，长度之和为 "<<sum<<"，长度最大值为 "<<maxi<<"；\n";
		return true;
	}
	else return false;
}

void dfs(int x){
	if(x == n){
		if(myWork1()) ans = (ans + 1) % MOD;
		return;
	}
	
	ar[x] = true;
	dfs(x+1);
	ar[x] = false;
	dfs(x+1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	dfs(0);
	
	cout<<ans<<endl;

	return 0;
}

/*

不多想了
本题打暴力
11:26:38 从传统暴力改成dfs
11:32:25 改完了

不写了，代码就这样了
估分：
T1 100
T2 100
T3 60
T4 30
290 best

T1 100
T2 100
T3 30
T4 30
260 medium

只要freopen都写对了应该就是这个分
我尽力了


IIIIIIIII        A      K    K        CCCCC     SSSSS   PPPPPPP        
    I           A A     K   K        C     C   S     S  P      P  
    I          A   A    K K         C          S        P      P
    I         A     A   KK          C           SSSSS   PPPPPPP   
    I         AAAAAAA   K K         C                S  P    
    I         A     A   K   K       C                S  P 
    I         A     A   K    K       C     C         S  P           
IIIIIIIII     A     A   K     K       CCCCC     SSSSS   P             
*/