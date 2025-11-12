#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number","r",stdin);
	string s;
	int b,i,j;
	scanf("%s",&s);
	b=100;
	char c[b+1],d[b+1];
	for(i=1;i<=b;i++){
		c[i]=s[i];
		cout<<c[i]<<endl;
	}
	for(i=1;i<=b;i++)
	{
		for(j=48;j<=57;i++)
		if(c[i]==j)
		printf("%d",j);
	}
	return 0;
}
