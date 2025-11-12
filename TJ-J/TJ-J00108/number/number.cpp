#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char c[2000002];
int d[2000002],len=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	int l=strlen(c+1);
	for(int i=1;i<=l;i++){
		if(c[i]>='0'&&c[i]<='9'){
			d[++len]=c[i]-48;
		}
	}
	sort(d+1,d+len+1,cmp);
	for(int i=1;i<=len;i++){
		printf("%d",d[i]);
	}
    return 0;
}

