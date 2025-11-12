#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[500005];
int t[5005][5005],v[5005][5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)x++;
		else if(!a[i])y++;
	}if(x==n){
		cout<<n/2;
		return 0;
	}if(x+y==n){
		if(m==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1)y++,i++;
			}cout<<y;
		}else cout<<x;
		return 0;
	}else {
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				t[i][j]=t[i][j-1]^a[i];
				if(t[i][j]==m)v[i][j]=1;
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++)
					v[i][j]=max(v[i][j],v[i][k]+v[k+1][j]);
			}
		}cout<<v[1][n];
	}return 0;
}
