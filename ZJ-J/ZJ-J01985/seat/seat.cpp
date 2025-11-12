#include<bits/stdc++.h>
using namespace std;
const int N=20,M=110;
int n,m,x[M],y[M],a[N][N],e,cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x[++cnt];
		}
	}
	e=x[1];
	sort(x+1,x+1+cnt);
	for(int i=1;i<=cnt;i++)y[i]=x[cnt+1-i];
	cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=y[++cnt];
				if(a[i][j]==e){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=y[++cnt];
				if(a[i][j]==e){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
