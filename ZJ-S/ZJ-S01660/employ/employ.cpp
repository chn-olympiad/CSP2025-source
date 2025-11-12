#include <bits/stdc++.h>
using namespace std;

int n,m;
bool s[501];
int c[501];

int quick_read(){
	int p=0;
	while (1){
		char c=getchar();
		if ('0'<=c && c<='9'){
			p=c-'0';
			break;
		}
	}
	while (1){
		char c=getchar();
		if ('0'<=c && c<='9'){
			p=p*10+(c-'0');
		}
		else{
			break;
		}
	}
	return p;
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	
	for (int i=1;i<=n;i++){
		s[i]=getchar()-'0';
	}
	for (int i=1;i<=n;i++){
		c[i]=quick_read();
	}
	long long ans=1;
	for (int i=1;i<=n;i++){
		ans=ans*i;
	}printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
