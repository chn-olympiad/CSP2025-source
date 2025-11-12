#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
const int N=1000005;
char a[N];
namespace Force{
	int c[20];
	void solve(){
		int n=strlen(&a[1]);
		//printf("%d\n",n);
		for(int i=1;i<=n;i++){
			if('0'<=a[i]&&a[i]<='9'){
				c[a[i]-'0']++;
			}
		}
		for(int i=9;i>=0;i--){
			for(int j=1;j<=c[i];j++){
				printf("%d",i);
			}
		}
		puts("");
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a[1]);
	Force::solve();
	return 0;
}
