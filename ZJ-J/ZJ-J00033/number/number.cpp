#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int p[20];
//inline int read(){
//	int x = 0, f = 1; char ch = getchar();
//	while(!isdigit(ch)){
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(isdigit(ch)){
//		x = (x << 3) + (x << 1) + (ch ^ 48);
//		ch = getchar();
//	}
//	return x * f;
//}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			p[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=p[i];j++)
			cout<<i;
	}
	return 0;
}

