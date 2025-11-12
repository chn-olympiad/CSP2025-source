#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x;

bool cmp(int l,int r){
	return l>r;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	int xx=1,yy=1,f=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)break;
		if(f==0){
			if(xx<n)xx++;
			else{
				yy++;
				f=1;
			}
		}
		else{
			if(xx>1)xx--;
			else{
				yy++;
				f=0;
			}
		}
	}
	cout<<yy<<" "<<xx;
	return 0;
}
