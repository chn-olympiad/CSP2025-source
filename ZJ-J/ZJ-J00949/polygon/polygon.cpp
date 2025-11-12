#include<bits/stdc++.h>
using namespace std;
const int N=10e7+5;
int n=0,a[N],tans=0;
void back(int s,int maxn,int p,int sum){
	for(int i=p;i>=1;i--){
		s+=a[i];
		sum++;
		if(sum>=3&&s>maxn){
			tans+=pow(2,i-1);
			tans%=998244353;
			s-=a[i];
			sum--;
			continue;
		}
		back(s,maxn,i-1,sum);
		s-=a[i];
		sum--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		back(0,a[i],i-1,1);
	}
	cout<<tans;
	return 0;
}