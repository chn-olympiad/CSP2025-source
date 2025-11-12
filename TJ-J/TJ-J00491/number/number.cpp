#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
int n;
const int maxn=1e6+5;
std::string str;
char tmp[maxn];
int a[maxn],len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&tmp[1]);
	str=&tmp[1];
	for(int i=0;i<(int)str.size();i++){
		if('0'<=str[i]&&str[i]<='9') a[++len]=str[i]-'0';
	}
	std::sort(a+1,a+len+1);
	for(int i=len;i>=1;i--) putchar(a[i]+'0');
	puts("");
	return 0;
}
