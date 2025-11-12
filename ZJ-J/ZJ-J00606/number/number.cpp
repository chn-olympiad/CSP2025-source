#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000002;
char Str[Maxn];
int Len=0;
int Cnt[12];
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",Str);
	Len=strlen(Str);
	for(int I=0;I<Len;++I){
		if(Str[I]>='0'&&Str[I]<='9'){
			++Cnt[Str[I]-'0'];
		}
	}
	for(int I=9;I>=0;--I){
		for(int J=1;J<=Cnt[I];++J){
			printf("%d",I);
		}
	}
	printf("\n");
	return 0;
}
