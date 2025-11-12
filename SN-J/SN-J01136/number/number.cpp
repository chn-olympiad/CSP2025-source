//考号：SN-J01136 姓名：霍启若 学校：蒲城县城南学校 
#include<iostream>
char s[1000005];
int a[13];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i = 0;i < sizeof(s);i++) if(s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	for(int i = 9;i >= 0;i--) while(a[i]--) printf("%d",i);
	return 0;
}
