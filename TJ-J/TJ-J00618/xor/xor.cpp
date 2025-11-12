#include<bits/stdc++.h>
using namespace std;
const int N=3e4-8000;
int d[N][N],n,k,a[N],l[N],maxn,flag;
/*
4 2
2 1 0 3

*/

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			d[i][j]=d[i][j-1]^a[j];
		}
	} 
	l[n]=(a[n]==k?1:0);
	for(int i=n-1;i>=1;i--){
		flag=0;
		l[i]=0;
		for(int j=i;j<=n;j++){
			if(flag==1){
				l[i]=max(l[i],l[j]+1);
			}
			if(d[i][j]==k&&!flag){
				flag=1;l[i]=1;
			}
		}
		maxn=max(maxn,l[i]);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
