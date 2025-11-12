// SN-J01134 雷曜玮 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[11][11],g[122],n,m,t,x=1,y=1,u;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	cin>>g[1];
	int c=g[1];
	for(int i=2;i<=s;i++) cin>>g[i];
	for(int i=1;i<=s;i++)
		for(int j=1;j<=s;j++)
			if(g[j]<g[j+1]){	
				t=g[j];
				g[j]=g[j+1];
				g[j+1]=t;
			}
	for(int i=1;i<=s;i++)
		if(g[i]==c){
		u=i;
		break;
	}
	if(u%n==0) y=u/n;
	else y=u/n+1;
	if(y%2==0) x=n-(u-(y-1)*n);
	else x=u-(y-1)*n;
	cout<<y<<" "<<x;
	return 0;
}
