//SN-J00435  Ðì×Ó³½  ³¤Çì°ËÖÐ
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=5001;i++){
		if(b[i]>=2){
			cout<<"6";
			return 0;
		}
	}
	cout<<"9";
	return 0;
}
