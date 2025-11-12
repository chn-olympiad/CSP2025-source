#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(n==1&&m==1){
		cout<<"1 1";
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]==r){
				cout<<i<<" 1";
			}
		}		
	}
	else if(n==1){
		for(int i=1;i<=m;i++){
			if(a[i]==r){
				cout<<"1 "<<i;
			}
		}	
	}
	else{
		int k=1;
		for(int i=1;i<=n;i++){
			if(i%2==1){
				for(int j=1;j<=m;j++){
					if(a[k]==r){
						cout<<i<<" "<<j;
						return 0;
					}
					k++;
				}
			}
			else{
				for(int j=m;j>=1;j--){
					if(a[k]==r){
						cout<<i<<" "<<j;
						return 0;
					}
					k++;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
