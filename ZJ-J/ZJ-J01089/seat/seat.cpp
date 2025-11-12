#include<bits/stdc++.h>
using namespace std;

const int N=110;
int n,m,r;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=(n*m);i++){
		cin>>a[i];
		if (i==1) r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	
	int x=1;
	for (int i=0;i<m;i++){
		if (i%2==0){
			for (int j=0;j<n;j++){
				if (a[x++]==r){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
		else{
			for (int j=n-1;j>=0;j--){
				if (a[x++]==r){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;	
} 
