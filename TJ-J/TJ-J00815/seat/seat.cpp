#include<bits/stdc++.h>
using namespace std;
int a[11][11],b[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int r=b[1],ri;
	sort(b+1,b+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==r)ri=i;
	}
	int ansx,ansy;
	ansx=ri/n;
	if(ansx%2==0)ansy=ri%n;
	else ansy=m-ri%n+1;
	if(ri%n==0)cout<<ansx<<' '<<m;
	else cout<<ansx+1<<' '<<ansy;
	return 0;
}

