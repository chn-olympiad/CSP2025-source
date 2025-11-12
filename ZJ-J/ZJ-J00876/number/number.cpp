#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		c=getchar();
		if(c=='\n')break;
		if(c>='0'&&c<='9')a[++n]=c-'0';
	}sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}
