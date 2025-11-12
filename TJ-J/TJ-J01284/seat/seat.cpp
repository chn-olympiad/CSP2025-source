#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m,f;
	cin>>n>>m;
	cin>>a[1];
	f=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=0,cnt=1;
	for(int i=1;i<=n*m;i++){
		if(cnt==1) r++;
		else if(cnt==0) r--;
		if(c%2==1 and r>n){
			r--;
			c++;
			cnt=0;
		}
		else if(c%2==0 and r<1){
			r++;
			c++;
			cnt=1;
		}
		if(a[i]==f){
			cout<<c<<' '<<r;
			return 0;
		}
	}
} 
