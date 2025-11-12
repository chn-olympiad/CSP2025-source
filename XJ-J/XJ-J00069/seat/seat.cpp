#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool f=true;
int a[15][15]={-1};
int b[250]={-1};
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++){
    	cin>>b[i];
	}
	const int o=b[1];
	sort(b,b+s);
	int h=0;
	for(int i=1;i<=s;i++){
		if(b[i]!=-1) h++;
	}
	int i=1,j=1;
    while(h--){
    	if(a[i][n]>0){
    		i++;
    		f=false;
		}
		if(a[1][j]>0){
			i++;
			f=true;
		}
		if(f){
			a[i][j]=b[h];
			j++;
		}
		else {
			a[i][j]=b[h];
			j--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==o) {
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	return 0;
}
