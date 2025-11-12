#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][5],w[10005],b[10005];


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>a[i][1];
    	a[i][4]=a[i][1];
    	cin>>a[i][2];
    	a[i][2]=a[i][3];
    	cin>>w[i];
	}
	for(int i=1;i<=k;i++){
		
	}
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}

	
