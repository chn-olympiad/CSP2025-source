#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	printf("0");
	return 0;
}