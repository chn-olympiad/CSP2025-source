#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],tot,des,pos,b[11][11],s;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tot=n*m;
	cin>>a[1];
	des=a[1];
	for(int i=2;i<=tot;i++)
		cin>>a[i];
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++)
				b[j][i]=a[++s];
		else
			for(int j=n;j>=1;j--)
				b[j][i]=a[++s];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(b[i][j]==des){
				cout<<j<<' '<<i;
				return 0;
			}
	}	
}
