#include<bits/stdc++.h>
using namespace std;
int n,m,r,h,s;
int a[100100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	h=1,s=1;
	if(a[1]==r){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(s%2==1){
			h++;
			if(h==n+1) h--,s++;
		}
		else{
			h--;
			if(h==0) h++,s++;
		}
		//cout<<s<<" "<<h<<"\n";
		if(a[i]==r){
			cout<<s<<" "<<h;
			return 0;
		}
	}
	return 0;
}
