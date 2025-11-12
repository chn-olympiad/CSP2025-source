#include <bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	int k=1,i=1,j=1;
	while(i<=n&&j<=m){
		if(a[k]!=r){
			if(j%2==0){
				if(i==1){
					j++;
				}else{
					i--;
				}
			}else{
				if(i==n){
					j++;
				}else{
					i++;
				}
			}
			
		}else{
			cout<<j<<" "<<i;
			break;
		}
		k++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
