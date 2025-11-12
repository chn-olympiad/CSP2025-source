#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while('0'>c||c>'9'){if(c=='-') f=-f;c=getchar();}
	while('0'<=c&&c<='9'){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=5e5+5;
struct node{
	int l;
	int r;
}x[N];
map<int,int> mp;
int n,k,f,ans;
int a[N],s[N];
bool cmp(node i,node j){
	return i.r<j.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]^a[i];
	}
	for(int i=n;i>=1;i--){
		mp[s[i]]=i;
		int pos=mp[s[i-1]^k];
		if(pos) x[++f]={i,pos};
	}
	sort(x+1,x+f+1,cmp);
	int R=0;
	for(int i=1;i<=n;i++){
		if(x[i].l>R) ans++,R=x[i].r;
	}
	cout<<ans;
	return 0;
}