#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long s;
bool v[5005];
void d(int h,int u){
	if(h==2){
		unsigned long long l=0;
		int o=0;
		for(int i=1;i<=n;i++){
			if(v[i]){
				o++;
				l+=a[i];
			}
		}
		l-=a[o];
		if(a[o]<l&&o>=3)s++,s=s%998244353;
		return;
	}
	for(int k=u;k<=n;k++){
		v[k]++;
		d(h-1,u+1);
		v[k]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		d(i,1);
	}
	cout<<s;
	return 0;
}
