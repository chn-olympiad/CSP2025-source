#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n=0,l,ans=0,a[1000001];
int x(char x){
	if(x=='1')
		return 1;
	else if(x=='2')
		return 2;
	else if(x=='3')
		return 3;
	else if(x=='4')
		return 4;
	else if(x=='5')
		return 5;
	else if(x=='6')
		return 6;
	else if(x=='7')
		return 7;
	else if(x=='8')
		return 8;
	else if(x=='9')
		return 9;
	else if(x=='0')
		return 0;
	else
		return 10;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	l=strlen(s+1);
	for(int i=1;i<=l;i++)
		if(x(s[i])!=10){
			n++;
			a[n]=x(s[i]);
		}
	for(int i=1;i<=n;i++)
		for(int j=i;j>1;j--)
			if(a[j]>a[j-1]){
				swap(a[j],a[j-1]);
			}
		
	
	for(int i=1;i<=n;i++)
		printf("%d",a[i]);
	return 0;
} 
