#include<bits/stdc++.h>
using namespace std;
inline bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int a=0;
	char d[1000010]={},c;
	while((c=getchar())!='\n'){
		if(c>='0' && c<='9'){
			d[++a]=c;
		}
	}
	sort(d+1,d+a+1,cmp);
	for(int b=1;b<=a;b++){
		putchar(d[b]);
	}
	return 0;
}
