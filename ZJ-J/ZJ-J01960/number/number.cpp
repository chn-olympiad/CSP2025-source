#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=1e6+5;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
char c[maxn];
int p[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	int s=strlen(c);
	for(int i=0;i<s;i++){
		if(c[i]>='0'&&c[i]<='9'){
			++p[c[i]-'0'];
		}
	}
	for(int i=9;i>=0;i--){
		while(p[i]--){
			putchar(i+'0');
		}
	}
	return 0;
}

