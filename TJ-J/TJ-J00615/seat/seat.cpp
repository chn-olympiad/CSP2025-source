#include<bits/stdc++.h>
using namespace std;
int a[1100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,e,x;
	bool p=1;
	cin>>n>>m;
	e=n*m;
	for(int i=1;i<=e;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+e+1,cmp);
	int i=1,j=1;
	for(int w=1;i<=e;w++){
		if(p){
			if(j>n){
				p=0;
				j=n;
				i++;	
			}
		}else if(j<1){
			p=1;
			j=1;
			i++;
		}
		if(x==a[w]){
			cout<<i<<" "<<j;
			return 0;
		}
		if(p){
			j++;
		}else{
			j--;
		}
	}
	return 0;
}
