#include<iostream>
#include<algorithm>
using namespace std;
char c[1000000];
int num[1000000],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	for(int i=0;c[i];i++){
		if(c[i]>='0'&&c[i]<='9')num[k]=c[i]-'0',k++;
	}sort(num,num+k);
	for(int i=k-1;i>=0;i--)putchar(num[i]+'0');
	return 0;
}
