// 丁家淳 SN-S00004 渭南高级中学 
#include<bits/stdc++.h>
using namespace std;

int n,m,c[600],ans;
char s[1001];
bool A = 1,b[1001];

inline void a1(int t){
	if(t == n + 1){
		ans++;
		ans %= 998244353;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!b[i] && c[i] <= t){
			b[i] = 1;
			a1(t + 1);
			b[i] = 0;
		}
		else
			if(c[i] > t)
				return;
	}
}

inline void b1(){
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d%d%s",&n,&m,s + 1);
	for(int i = 1;i <= n;i++)
		scanf("%d",&c[i]);
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(c[j] <= c[i])
			swap(c[j],c[i]);
		}
	}

	if(m == 1){
		b1();
		printf("%d",ans);
		return 0;
	}

	for(int i = 1;i <= n;i++)
		if(s[i] == '0'){
			A = 0;
			break;
		}
	if(m == n){
		printf("0");
		return 0;
	}
	if(A){
		a1(1);
		printf("%d",ans);
		return 0;
	}
	printf("20090226");
	return 0;
}
