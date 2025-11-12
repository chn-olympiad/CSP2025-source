#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,b[15][15],k=1;
bool bo(int q,int w){
	if(q>w)return true;
	if(w>q)return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+m*n+1,bo);
    for(int i=1;i<=n;i++){
    		if(i%2==1)for(int j=1;j<=m;j++){
    		b[i][j]=a[k];
			k++;	
			}
            else for(int j=m;j>=1;j--) {
            b[i][j]=a[k];
			k++;	
			}
	}
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    if(b[i][j]==x){
	cout<<i<<" "<<j;
	return 0;
}
	return 0;
}



































