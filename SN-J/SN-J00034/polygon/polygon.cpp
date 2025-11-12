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
int maxxx(int a[10010],int b){
	int maxx=INT_MIN;
	for(int i=0;i<b;i++){
		maxx=max(a[i],maxx);
	}
	return maxx;
}
int a[10010],mat,mat2; 
int main(){
	freopen("polygon.in","r", stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++){
		a[i]=read();
	}
	mat=maxxx(a,3);
	if((a+b+c)>mat*2) cout << 1;
	else cout << n+1;
	return 0;
}

