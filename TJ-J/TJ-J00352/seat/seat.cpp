#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long a[10001],b[10001],nn[10001],n[10001],x,y,cs=0,xx;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	xx=x;
	for(int i=0;i<x*y;i++){
		cin>>nn[i];
	}
	int sum=nn[0];
	sort(nn,nn+x*y);
	for(int i=x*y-1;i>=0;i--){
		n[cs]=nn[i];
		cs++;
	}
	cs=0;
	int i=0;
	while(cs!=y){
		for(i=i;i<x;i++){
			a[i]=n[i];
			if(a[i]==sum&&i+1<=xx&&cs<=y)
				cout<<cs+1<<" "<<i+1;
			else if((a[i]==sum&&i+1>xx&&(i+1)%xx!=0)&&(cs<=y&&i%xx!=0))
					cout<<cs+1<<" "<<(i+1)%xx;
			else if((a[i]==sum&&i+1>xx&&(i+1)%xx!=0)&&(i%xx!=0&&cs>y))
					cout<<(cs+1)%y<<" "<<(i+1)%xx;
			else if((a[i]==sum&&i+1<=xx)&&cs>y)
					cout<<(cs+1)%y<<" "<<i+1;
			else if(a[i]==sum&&((i+1)%xx==0||i%xx==0)&&cs>y)
					cout<<(cs+1)%y<<" "<<xx;
			else if(a[i]==sum&&((i+1)%xx==0||i%xx==0)&&cs<=y)
					cout<<cs+1<<" "<<xx;
		}
		cs++;
		if(cs==y){
			break;
		}
		x+=xx;
		for(i=i;i<x;i++){
			b[i]=n[i];
			if(b[i]==sum&&i+1<=xx&&cs<=y)
				cout<<cs+1<<" "<<i+1;
			else if((b[i]==sum&&i+1>xx&&(i+1)%xx!=0)&&(cs<=y&&i%xx!=0))
					cout<<cs+1<<" "<<(i+1)%xx;
			else if((b[i]==sum&&i+1>xx&&(i+1)%xx!=0)&&(i%xx!=0&&cs>y))
					cout<<(cs+1)%y<<" "<<(i+1)%xx;
			else if((b[i]==sum&&i+1<=xx)&&cs>y)
					cout<<(cs+1)%y<<" "<<i+1;
			else if(b[i]==sum&&((i+1)%xx==0||i%xx==0)&&cs>y)
					cout<<(cs+1)%y<<" "<<xx;
			else if(b[i]==sum&&((i+1)%xx==0||i%xx==0)&&cs<=y)
					cout<<cs+1<<" "<<xx;
		}
		cs++;
		x+=xx;

	}
	return 0;
}
