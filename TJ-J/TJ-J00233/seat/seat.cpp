#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	int a[100011];
	long long q=m*n-1;
	for(int i=0;i<=q;i++){
		cin>>a[i];
	}long long g=a[0];
	sort(a,a+q+1);

	int x=1,y=1,z=0,j=0;

	long long w,e;
	for(int i=q;i>=0;i--){
		if(a[i]==g){
			w=i;
		}
	}
	w=q-w;
	e=w+1;
	w/=n;
	w+=1;
	if(w%2!=0){
		if(e%m==0){
			e=m;
		}else{
			e=e%m;
			
		}
	}else{
		if(e%m==0){
			e=1;
		}else{
			e=m-e%m+1;
			
		}
	}
	cout<<w<<" "<<e;
	return 0;
}
