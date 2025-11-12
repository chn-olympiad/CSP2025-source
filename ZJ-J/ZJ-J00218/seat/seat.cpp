#include<bits/stdc++.h>
using namespace std;
struct data{
	int cj,s;
}a[1001];
int n,m;
int cmp(data a,data b)
{
	return a.cj>b.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].s=i;
	}
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].cj<<' ';
//	}
	int x=0,ls=1,pd=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].s==1){
			x+=pd;
			cout<<ls<<" "<<x;
			return 0;
		}
		else{
			x+=pd;
			if(x==n){
				pd=-1;
				ls+=1;
				i++;
				if(a[i].s==1){
					cout<<ls<<" "<<x;
					return 0;
				}
			}
			if(x==1&&i!=1){
				pd=1;
				ls+=1;
				i++;
				if(a[i].s==1){
					cout<<ls<<" "<<x;
					return 0;
				}
			}
		}
//		cout<<ls<<" "<<x<<'\n';
	}
	return 0;
}