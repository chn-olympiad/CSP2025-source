#include<cstdio>
#include<algorithm>
char s[1000012];
int a[1000012];
int m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s[1]);
	//for(int i=1;s[i];i++)printf("%c",s[i]);
	//puts("");
	//for(int i=1;s[i];i++)printf("%c",s[i]);
	//puts("");
	for(int i=1;s[i]!='\n';i++){
		//for(int j=1;s[j]!='\n';j++)printf("%c",s[j]);
		//puts("");
		if(s[i]=='\n')break;
		//printf("%c",s[i]);
		if(s[i]>='0'&&s[i]<='9'){
			//printf("%c",s[i]);
			//puts("");
			m++;
			a[m]=s[i]-'0';
		}
	}
	//for(int i=1;s[i];i++)printf("%c",s[i]);
	//puts("");
	//for(int i=1;i<=m-1;i++)printf("%d",a[i]);
	//puts("");
	std::sort(&a[1],&a[m]);
	m--;
	for(int i=m;i>=1;i--)printf("%d",a[i]);
	puts("");
	return 0;
}
