#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1,a[110];
bool f=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1;
	while(p!=a[i]){
		++i;
		if(f){
			++r;
			if(r>m){
				r=m;
				++c;
				f=!f;
			}
		}else{
			--r;
			if(r==0){
				r=1;
				++c;
				f=!f;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}

