#include<cstdio>//AC
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+10;
char arr[N];
char b[N];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",arr);
	int x=0;
	for(int i=0;arr[i]!=0;i++){
		int c=arr[i];
		if(c>='0'&&c<='9'){
			b[x++]=arr[i];
		}
	}
	b[x]=0;
	sort(b,b+x,cmp);
	printf("%s",b);
	
	return 0;
}
