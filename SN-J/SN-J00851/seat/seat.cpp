#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m,q;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	bool flag=false; 
	int flag2=-1;
	int c=1,r=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			cout<<c<<" "<<r;
			return 0;
		}
		if (flag){
			c++;
			flag=false;
		}
		else{
			if(flag2){
				r-=1;
			}
			else{
				r+=1;
			}
			if(r==1||r==m){
				flag=true;flag2=-flag2;
			}
		}
	}
	return 0;
}
