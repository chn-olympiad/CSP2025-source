#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn=1000005;
char str[maxn];
int a[maxn];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",&str[1]);
	int n=strlen(&str[1]);
	int len=0;
	for(int i=1;i<=n;i++){
		if('0'<=str[i]&&str[i]<='9') a[++len]=str[i]-'0';
	}
	
	std::sort(a+1,a+len+1,cmp);
	
	for(int i=1;i<=len;i++) printf("%d",a[i]);
	puts("");
	return 0;
}
