#include<bits/stdc++.h>
using namespace std;
int n,m,d[500010],x,y,ma=-2e9;
int main(){
//	freopen("xor.in","r",stdin); 
//	freopen("xor.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int t=i;t<=j;t++){
				x=x^d[t];
			}
			if(x==m){
				y++;
			}
		}
		ma=max(ma,y);
		y=0;
	}
	cout<<ma;
	
	return 0;
}

