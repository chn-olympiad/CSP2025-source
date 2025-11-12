#include<bits/stdc++.h>
using namespace std;
long long cj[105],zw[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	long long r=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				zw[j][i]=cj[p];
				if(zw[j][i]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				p++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				zw[j][i]=cj[p];
				if(zw[j][i]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				p++;
			}
		}
	}
	return 0;
}

