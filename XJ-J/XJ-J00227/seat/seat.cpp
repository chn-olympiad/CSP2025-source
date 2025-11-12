#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],w,s[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	w=s[1];
	sort(s+1,s+n*m+1,cmp);
	if(w==s[1])
		cout<<1<<' '<<1;
	else
		cout<<m<<' '<<n;
	/*w=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=n+1;j<=n+m+1;j++){
			if(j%2!=0)
				a[i][j]=s[i*j];
			else
				a[n-i+1][j]=s[i*j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n+1;j<=n+m+1;j++){
			if(s[i*j]==w){
				cout<<i<<' '<<j-n-1;
				return 0;
			}
		}
	}*/
	return 0;
}
