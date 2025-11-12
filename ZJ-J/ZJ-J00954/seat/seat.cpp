#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],c,d=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			b[i][j]=a[d];
			if(a[d]==c){
				cout<<j<<" "<<i;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			d++;
		}
		j++;
		for(int i=n;i>0;i--){
			b[i][j]=a[d];
			if(a[d]==c){
				cout<<j<<" "<<i;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			d++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
