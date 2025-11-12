#include <cstdio>
namespace h{
	const int maxn=1000000+4;
	int a[maxn];
	bool has[maxn];
	long long ans;
	int len=0;
	void dfs(int now){
		if(now>len){
			long long num=0;
			for(int i=1;i<=len;i++)
				if(has[i]) num=num*10+a[i];
			if(num>ans) ans=num;
			return;
		}
		for(int i=1;i<=len;i++){
			if(!has[i]){
				has[i]=true;
				dfs(now+1);
				has[i]=false;
			}
		}
	}
	void s(){
		for(int i=1;;i++){
			char t;
			scanf("%c",&t);
			if(t!=EOF){
				if('0'<=t&&t<='9'){
					a[++len]=t-'0';
				}
			}else break;
		}
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	h::s();
	return 0;
}
