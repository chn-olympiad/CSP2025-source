#include<bits/stdc++.h>
using namespace std;
struct node{
	long long fs;
	bool flagR;
}a[1000];
bool cmp(node p,node h){
	return p.fs>h.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long ls=n*m;
	for(long long i=1;i<=ls;i++){
		cin>>a[i].fs;
		if(i==1)a[i].flagR=1;
		else a[i].flagR=0;
	}
	sort(a+1,a+1+ls,cmp);
	for(long long i=1;i<=ls;i++){
		if(a[i].flagR==1){
			long long hang=ceil(1.0*i/n);
			if(hang%2==1){
				int zhenghang=i%n;
				if(zhenghang==0)zhenghang=n;
				cout<<hang<<' '<<zhenghang<<'\n';
			}else{
				int zhenghang=n-i%n;
				cout<<hang<<' '<<zhenghang<<'\n';
			}
			return 0;
		}
	}
	return 0;
}
