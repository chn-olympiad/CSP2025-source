#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],z;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int l;
			if(i%n==0) l=i/n;
			else l=i/n+1;
			if(l%2==1){
				int h=i%n;
				if(h==0) h=n;
				cout<<l<<" "<<h;
				return 0;
			}
			else{
				cout<<l<<" "<<n-i%n+1;
				return 0;
			}
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
