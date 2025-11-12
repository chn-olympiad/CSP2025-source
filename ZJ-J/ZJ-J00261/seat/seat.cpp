#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=15;
int a[N][N],num[N*N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	IOS
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
		if(num[i]>num[1])
			cnt++;
	}
	for(int i=1;i<=n;i++){
		int t=n*m,f=2*(n-i)+1;
		a[i][1]=t-i+1;
		for(int j=2;j<=m;j++){
			if(j%2==0)
				a[i][j]=a[i][j-1]-f;
			if(j%2==1)
				a[i][j]=a[i][j-1]-((i-1)*2+1);
		}
	}
	sort(num+1,num+n*m+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]+cnt==n*m){
				cout<<j<<" "<<i;
				return 0;
			}	
	return 0;
}

