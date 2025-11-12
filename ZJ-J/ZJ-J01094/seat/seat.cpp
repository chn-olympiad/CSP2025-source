#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=200;
int a[maxn];
int cnt;
bool cmp(int i,int j){
	return i>j;
}
int sta;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[++cnt];
	sta=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(sta==a[i]){
			int h=i/n+1;
			int l=i%n;
			if(l==0){
				l=n;
				h--;
			}
			if(h&1) cout<<h<<" "<<l<<endl;
			else cout<<h<<" "<<n-l+1<<endl;
			return 0;
		}
	}
	return 0;
}
