//SN-J00488 朱毅然 招安镇初级中学
#include<bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001];
int c=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	for(int i=1;i<=strlen(a+1);i++)
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=a[i];
			c++;
		}
	sort(b+1,b+strlen(b+1)+1);
	for(int i=strlen(b+1);i>=1;i--) cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
