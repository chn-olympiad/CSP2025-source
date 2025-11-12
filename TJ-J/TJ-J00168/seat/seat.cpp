#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,x,h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			x=i;
		}
	}
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			cout<<l<<" "<<h;
			break;
		}
		if(l%2==1){
			if(h%n==0){
				l++;
			}else{
				h++;
			}
		}else{
			if(h==1){
				l++;
			}else{
				h--;
			}
		}
	}
	return 0;
}
//ÁÐ£ºnum/n+1 
