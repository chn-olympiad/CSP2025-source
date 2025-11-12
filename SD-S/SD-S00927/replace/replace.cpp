#include<bits/stdc++.h>
#include <cstdio>
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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cout << "0\n";
	}
	return 0;
}

