//SN-J01053  TongChuanShiTaoYuanDiErZhongXiaoXue  HaoTianZhe
#include <bits/stdc++.h>
using namespace std;
char s[100001];
bool cmp(int x,int y){
	return (x>y);
}
int a[1000001],l;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if((s[i]>='0')&&(s[i]<='9')){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l,cmp);
	bool f=0;
	for(int i=l;i>=1;i--){
		if(a[i]!=0){
			f=1;
			break;
		}
	}
	if(!f){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=l;i++){
		printf("%d",a[i]);
	}
	return 0;
}
