#include <bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	return 0;
}

