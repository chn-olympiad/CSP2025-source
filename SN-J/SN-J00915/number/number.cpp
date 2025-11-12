//MZKXGDFZ
#include<bits/stdc++.h>
using namespace std; 
int s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&s);
	if(s<10)printf("%d",s);
	else if(s<100){
		int a=s/10;
		int b=s%10;
		if(a>=b)printf("%d",s);
		else printf("%d",b*10+a);
	}
	return 0;
}
