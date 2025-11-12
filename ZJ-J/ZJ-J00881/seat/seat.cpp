#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],b[114][514];
bool cmp(int x,int y){
	return (x>y?true:false);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+n*m,cmp);
	int j;
	
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			j=i+1;
		}
	}
	if(n==1){
		if(m==1){
			cout<<1<<" "<<1;
			return 0;
		}else{
			cout<<j<<" "<<1;
			return 0;
		}
	}
	int k=0;
	int p=1;
	while(p<n*m){
		if(k%2==0){
			for(int i=0;i<n;i++){
				b[i][k]=p;
				p++;
			}
		}else{
			for(int i=n-1;i>=0;i--){
				b[i][k]=p;
				p++;
			}
		}
		k++;
	}
	for(int i=0;i<n;i++){
		for(int ii=0;ii<m;ii++){
			if(b[i][ii]==j){
				cout<<ii+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
