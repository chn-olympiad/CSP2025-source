#include<bits/stdc++.h>
using namespace std;
int a[11][11],b[101],r,m,n,cnt=1;
bool cmp(int f,int r){
	return f>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	r=b[1];
	sort(b+1,b+101,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int w=1;w<=n;w++){
				a[w][i]=b[cnt];cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[cnt];cnt++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(a[i][j]==r)cout<<j<<' '<<i;
		}
	}
	
	
	return 0;
}
