#include<bits/stdc++.h>
using namespace std;
int n,m,a[104],R,len;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+len,cmp);
	int p=0;
	for(int i=1;i<=len;i++){
		if(a[i]==R) p=i;
	}
	int t=p%(2*n);
	cout<<(p-1)/n+1<<' '<<(t<=n?t:2*n-t+1);
	return 0;
}