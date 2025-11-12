#include<bits/stdc++.h>
using namespace std;
int a[105],p,n,m;
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
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) p=i;
	}
	int w=floor((double)p/n*1.0);
	if(p%n==0){
		if(w%2==0){
			cout<<w<<" "<<"1";
			return 0;
		}
		else{
			cout<<w<<" "<<n;
			return 0;
		}
	}
	else if(p%n==1){
		if((w+1)%2==0){
			cout<<w+1<<" "<<n;
			return 0;
		}
		else{
			cout<<w+1<<" "<<"1";
			return 0;
		}
	}
	else{
		if(((p/n)+1)%2==0){
			cout<<w+1<<" "<<m-(p%n)+1;
			return 0;
		}
		else{
			cout<<w+1<<" "<<p%n;
			return 0;
		}
	}
	return 0;
}
