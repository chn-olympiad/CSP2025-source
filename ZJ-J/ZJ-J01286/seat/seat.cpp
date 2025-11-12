#include <bits/stdc++.h>
using namespace std;
int n,m,size,i,j,wz;
struct no{
	int fs,xa;
}a[10010];
bool cmp(no q,no h){
	return q.fs>h.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;size=n*m;
	for(i=1;i<=size;i++){
		cin>>a[i].fs;
		if(i==1) a[i].xa=1;
	}
	sort(a+1,a+size+1,cmp);
	for(i=1;i<=size;i++)
		if(a[i].xa==1)break;
	wz=i;
	for(i=1;i<=n;i++)
		if(i%2==1)
			for(j=1;j<=m;j++){
				wz--;
				if(wz==0){
					cout<<i<<" "<<j;return 0;
				}
			}
		else if(i%2==0)
			for(j=m;j>=1;j--){
				wz--;
				if(wz==0){
					cout<<i<<" "<<j;return 0;
				}
			}
}