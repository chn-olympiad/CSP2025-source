#include<cstdio>
const int maxn=1000005;
char s[maxn];
int a[maxn],c[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s[1]);
	int n=0;
	for(int i=1;;i++){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
			n++;
		}else{
			break;
		}
	}
	int m=0;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			if(s[i]=='0'){
				a[++m]=0;
			}
			if(s[i]=='1'){
				a[++m]=1;
			}
			if(s[i]=='2'){
				a[++m]=2;
			}
			if(s[i]=='3'){
				a[++m]=3;
			}
			if(s[i]=='4'){
				a[++m]=4;
			}
			if(s[i]=='5'){
				a[++m]=5;
			}
			if(s[i]=='6'){
				a[++m]=6;
			}
			if(s[i]=='7'){
				a[++m]=7;
			}
			if(s[i]=='8'){
				a[++m]=8;
			}
			if(s[i]=='9'){
				a[++m]=9;
			}
		}
	}
	for(int i=1;i<=m;i++){
		c[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++) printf("%d",i);
	}
	puts("");
	return 0;
}
