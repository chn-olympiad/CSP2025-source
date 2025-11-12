#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while('0'>c||c>'9'){if(c=='-') f=-f;c=getchar();}
	while('0'<=c&&c<='9'){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=105;
int n,m;
int a[N];
bool cmp(int i,int j){return i>j;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
	}
	sort(a+2,a+n*m+1,cmp);
	int ans=n*m;
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i]){
			ans=i-1;
			break;
		}
	}
	int lie=(ans-1)/n+1,hang;
	if(lie&1) hang=(ans-1)%n+1;
	else hang=n+1-((ans-1)%n+1);
	cout<<lie<<" "<<hang;
	return 0;
}