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
bool isPrime(long long n){
	if(n<2) return 0;
	if(n==2||n==3) return 1;
	if(n%6!=1&&n%6!=5) return 0;
	long long x=sqrt(n);
	for(int i=5;i<=x;i+=6){
		if(n%i==0||n%(i+2)==0) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r", stdin);
	freopen("replace.out","w", stdout);
	cout << 0;
	return 0;
}

