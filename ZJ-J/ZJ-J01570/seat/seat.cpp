#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int n,m;
int a[maxn];
int Rs;
int x;
int h;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==0||m==0){
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	Rs=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==Rs){
			x=i;
			break;
		}
	}
	int s=x%n;
	if(s==0){
		s=n;
	}
	if(((x-1)/n+1)%2==0){
		h=n-s+1;
	}else{
		h=s;
	}
	printf("%d %d\n",(x-1)/n+1,h);
	return 0;
}