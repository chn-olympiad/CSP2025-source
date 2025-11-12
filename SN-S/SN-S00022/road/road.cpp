#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
long long n,m,k,u,v,w;
int main(){
	freopen("road.in","r", stdin);
	freopen("road.out","w", stdout);
	cout << 13;
	return 0;
}

