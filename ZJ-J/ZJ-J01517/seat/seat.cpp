#include<bits/stdc++.h>
using namespace std;
int a[110],k,m,n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0);
	cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int q=1,p=1;
	for(int i=1;i<=n*m;i++){
		
		if(a[i]==k){
			cout<<p<<" "<<q;
			break;
		}
		if(p%2==1){
			if(q==n){
				p++;
			}else{
				q++;
			}
		}else{
			if(q==1){
				p++;
			}else{
				q--;
			}
		}
	}
	return 0;
}
