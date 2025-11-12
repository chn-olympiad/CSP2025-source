#include<cstdio>
#include<cstring>
#include<algorithm>
namespace force{
	const int MAXN=1e6+5;
	char a[MAXN];
	int num[15];
	void solve(){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		int l=0;
		for(int i=1;;i++){
			scanf("%c",&a[i]);
			if(a[i]=='\n'||a[i]==EOF) break;
			l++;
		}
		for(int i=1;i<=l;i++){
			if(a[i]>='0'&&a[i]<='9') num[a[i]-'0']++;
		}
		for(int i=9;i>=0;i--){
			for(int j=1;j<=num[i];j++) printf("%d",i);
		}
		puts("");
	}
}
int main(){
	force::solve();
	return 0;
}
