#include <cstdio>
#include <cstring>
const int maxn=2*100000+4;
const int maxabc=100+4;
char a[maxn][2][maxabc],b[maxabc],c[maxabc]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%s%s",&a[i][1][1],&a[i][2][1]);
	for(int _=1;_<=q;_++){
		scanf("%s%s",&b[1],&c[1]);
		int blen=strlen(&b[1]),clen=strlen(&c[1]);
		int num=0;
		for(int i=1;i<=n;i++){
			if(blen==strlen(&a[i][1][1])) num++;
			if(clen==strlen(&a[i][2][1])) num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
