#include<bits/stdc++.h>
using namespace std;

bool cmp(int n,int m){
	return n>m;
}
int a[105];
int main(){
	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i <= k;i++)  cin>>a[i];
	int x=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i <= k;i++){
		float d=i;
		if(x==a[i]){
			int ansx,ansy;
			ansx=ceil(d/n);
			if(ansx%2==1){
				if(i%n==0)  ansy=n;
				else  ansy=i%n;
			}
			else  ansy=n-i%n+1;
			cout<<ansx<<" "<<ansy;
			return 0; 
		}
	}
}