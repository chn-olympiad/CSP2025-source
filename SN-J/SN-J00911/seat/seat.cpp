#include<bits/stdc++.h> 
using namespace std;
long long m,n,k,a[110],R,h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==R){
			if(i%n==0){
				l=i/n;
			}else{
				l=i/n+1;
			}
			if(l%2!=0){
				h=i-(l-1)*n;
			}else{
				h=n+1-(i-(l-1)*n);
			}
			break;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
