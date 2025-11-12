#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int k;
int a[15][15];
int b[400],bg[400],gbg[400];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			k++;
			b[k]=a[i][j];			
		}
	}
	int ans=a[1][1];
	sort(b+1,b+k+1);
	int j=0;
	for(int i=k;i>=1;i--){
		j++;
		bg[j]=b[i];
	}
	k=0;
	int cs=1;
	int aj=j;
	for(int zjj=1;zjj<=aj/n;zjj++){
	int l=1;
	for(int i=cs*(j/n)+1;i<=cs*(j/n)+n;i++,l++){
		gbg[l]=bg[i];
	}
	sort(gbg+1,gbg+n+1);
	for(int xx=1,i=cs*(j/n)+1;i<=cs*(j/n)+n;xx++,i++){
		bg[i]=gbg[xx];
	}
	cs+=2;
}
int v;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			v++;
			a[i][j]=bg[v];
			if(ans==a[i][j]){
				cout<<i<<" "<<j;
				return 0;
			}	
		}
	}
	return 0; 
}
