#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105][105];
bool emp(int x,int y){
	if(x<y){
		return x>y;
	}
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
int y,x=0;
for(int i=0;i<n*m;i++){
	cin>>a[i];
	y=a[0];
}
sort(a,a+n*m,emp);
int i=1,j=1;
while(true){
	b[i][j]=a[x];
	if(b[i][j]==y){
		cout<<j<<" "<<i;
		return 0;
	}
	x++;
	if(j%2==1){
		if(i==n){
			j++;
		}else{
			i++;
		}
	}else{
		if(i==1){
			j++;
		}else{
			i--;
		}
	}
}
return 0;
}
