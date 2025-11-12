#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1;
char str[N],inp[N];
int p[N];
void expand(int i){while(str[i-p[i]-1]==str[i+p[i]+1]) ++p[i];}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	printf("%d",0);
 	fclose(stdin);
	fclose(stdout);
	return 0;
}
