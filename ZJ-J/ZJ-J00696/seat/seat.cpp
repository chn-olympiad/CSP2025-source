#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int p=a[0];
	sort(a,a+n*m);
	int b=1;
	int d=1;
	int k=0;
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==p) break;
		if(k==0){
			if(b+1<=n) b++;
			else{
				d++;
				k=1;
			}
		}
		else if(k==1){
			if(b-1>=1) b--;
			else{
				d++;
				k=0;
			}
		}
	}
	cout<<d<<' '<<b;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
