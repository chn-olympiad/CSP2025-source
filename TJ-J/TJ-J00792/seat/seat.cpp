#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,aa;
	cin>>n>>m;
	int nn=n*m;
	for(int i=1;i<=nn;i++){
		cin>>a[i];
	}
	aa=a[1];
	sort(a+1,a+1+nn,cmp);
	for(int i=1;i<=nn;i++){
		if(a[i]==aa){
			aa=i;
		}
	}
	if(aa<=n&&aa<=m){
		cout<<1<<" "<<aa<<endl;
	}else{
		cout<<2<<" "<<aa<<endl;
	}


	return 0;
}

