#include<bits/stdc++.h>
using namespace std;
struct _{
	int num=-1;
	char out[1145140];
}a[11];
char tmp='a';
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&tmp)!=EOF){
		if(tmp>='0'&&tmp<='9')
		a[tmp-'0'].out[++a[tmp-'0'].num]=tmp;
	}
	bool cnt=0;
	for(int i=9;i>=0;i--){
		if((i>0||(i==0&&cnt))&&a[i].num!=-1)
		{cout<<a[i].out;cnt=1;}
		else if(i==0&&!cnt)
		cout<<0;
	}
}
