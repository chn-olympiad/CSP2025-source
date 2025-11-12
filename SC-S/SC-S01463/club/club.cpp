#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T,sum;
struct sot{
	int f,s,t,la;
}a[100010];
bool cmp(sot x,sot y){
	return x.la>y.la;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			a[i].la=a[i].f-a[i].s;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			if(a[i].t>a[i].f)sum+=a[i].t;
			else sum+=a[i].f;
		}
		for(int i=n/2+1;i<=n;i++){
			if(a[i].t>a[i].s)sum+=a[i].t;
			else sum+=a[i].s;
		}
		cout<<sum<<'\n';
	}
	return 0;
}