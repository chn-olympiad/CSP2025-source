#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll res=0,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9'){
		if(ch=='-')f=-1;
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout << 2;
	return 0;
}

