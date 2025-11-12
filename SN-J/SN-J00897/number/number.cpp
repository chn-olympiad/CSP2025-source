#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000000;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char str[N];
	scanf("%s",str);
	char str2[N];
	int j=0;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]>='0'&&str[i]<='9'){
			str2[j]=str[i];
			j++;
		}
	}	
	sort(str2,str2+j+1,cmp);
	printf("%s",str2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//SN-J00897
//七年级
//西安南苑中学
//胡仲天
