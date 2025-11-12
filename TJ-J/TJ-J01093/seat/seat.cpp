#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>m>>n;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
    	cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+sum+1,cmp);
	int t=1,t1=0;
	for(int i=1;i<=sum;i++){
		if(t%2!=0){
			t1++;
			if(t1==n){
				b[t][n]=a[i];
				t++;
				t1=0;
			}
			else{
			b[t][(i+n)%n]=a[i];				
			}
		}
		else{
			t1++;
			if(t1==n){
				b[t][1]=a[i];
				t1=0;
				t++;
			}
			else{
				b[t][n-t1+1]=a[i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==ans){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

