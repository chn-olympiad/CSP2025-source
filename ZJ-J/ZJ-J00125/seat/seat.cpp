#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,y,f;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i/n;
			y=i%n;
			break;
		}
	}
	if(y==0){
		if(s%2==0){
			cout<<s<<" "<<1;
		}else{
			cout<<s<<" "<<n;
		}
	}else{
		if(s%2==0){
			cout<<s+1<<" "<<y;
		}else{
			cout<<s+1<<" "<<n-y+1;
		}
	}
	return 0;
}
