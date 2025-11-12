/*
直接输入字符串
并提取当中所有数字存入数组
进行sort排序（从大到小）
按数组从左往右输出
即为最大 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char s[1000005];
int num[1000005]={};

bool cmp(int l,int r)
{
	return l>r;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s+1);
	int len=strlen(s+1),j=1;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num+1,num+j,cmp);
	for(int i=1;i<j;i++){
		printf("%d",num[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
