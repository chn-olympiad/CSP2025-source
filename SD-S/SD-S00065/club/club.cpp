#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct w{
	int d1,d2,d3;
}a[100005]={};
bool cmp(w a,w b){
	return (a.d1-a.d2)>(b.d1-b.d2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		bool A=0,B=0,C=0;
		for(int i=1;i<=n;i++){
			cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
			if(a[i].d3>0)B=1;
		}
		if(!B){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=(n/2);i++)ans+=a[i].d1;
			for(int i=(n/2+1);i<=n;i++)ans+=a[i].d2;
			cout << ans << endl;
		}
	}
	return 0;
}
