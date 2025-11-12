#include<bits/stdc++.h>
#define ll longlong;
using namespace std;
inline rd(){
	int ans=0,f=0;
	char ch=getchar();
	while(ch>'0'||ch<'9') f^=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return f?-ans:ans;
}
int n,t;

const int N=1e5+5;
int a[N][3];
int maxl=0;
int maxs=0;
int maxt=0;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

	int zuidal=0;
	t=rd();
	n=rd();
for(int i=1;i<=t;i++){
	if(n%2!=0) break;
	for(int j=1;j<=n;j++){
		for(int y=0;y<3;y++){
	   a[j][3]=rd();
		}

	 }
    sort(a[N][1],a[N][1]+n);
	for(int c=0;c<n/2;c++){
	maxl=a[c][1]+a[c+1][1];
	
	sort(a[N][2],a[N][2]+n);
	for(int c=0;c<n/2;c++){
	maxs=a[c][2]+a[c+1][2];
	
	 sort(a[N][3],a[N][3]+n);
	for(int c=0;c<n/2;c++){
	maxt=a[c][3]+a[c+1][3];
	
	zuidal=maxl+maxs+maxt;
	cout>>zuidal;
  }
    return 0;
}
