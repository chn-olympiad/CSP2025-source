#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a=0,z=1;
	cin>>n>>m;
	int chengji[n*m],weizhi[n][m];
	for(int i=1;i<=n*m;i++){
		cin>>chengji[i];
		if(i==1){
			a=chengji[i];
		}
	}
	sort(chengji+1,chengji+n*m+1,cmp);
    for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				weizhi[j][i]=chengji[z];
				z++;
			}
		}else{
			for(int j=m;j>=1;j--){
				weizhi[j][i]=chengji[z];
				z++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		    if(weizhi[i][j]==a){
		    	cout<<j<<" "<<i;
		    	return 0;
			}
	    }
	}
	return 0;
} 
