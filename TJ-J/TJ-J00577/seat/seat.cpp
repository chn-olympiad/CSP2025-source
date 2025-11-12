#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,sc;
}a[105];
int n,m,k;
bool cmp(node x,node y){
	return x.sc>y.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,k=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++,k++){
				if(a[k].id==1){
					cout<<i<<' '<<j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--,k++){
				if(a[k].id==1){
					cout<<i<<' '<<j;
				}
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
}
