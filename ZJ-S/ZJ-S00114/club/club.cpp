#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,maxn;
int b[100];
struct good1{
	int hao,shu;
};
struct good{
	good1 da[10];
}a[100005];
bool cmp1(good1 x,good1 y){
	return x.hao > y.hao ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].da[1].hao >>a[i].da[2].hao>>a[i].da[3].hao;
			a[i].da[1].shu =1;
			a[i].da[2].shu =2;
			a[i].da[3].shu =3;
			sort(a[i].da +1,a[i].da +4,cmp1);
		}
		int maxn=INT_MIN,sum=0;
		for(int i=1;i<=n;i++){
			if(b[a[i].da[1].shu]<n/2){
				b[a[i].da[1].shu]++;
				sum+=a[i].da [1].hao;
			}
			else if(b[a[i].da[2].shu]<n/2){
				b[a[i].da[2].shu]++;
				sum+=a[i].da [2].hao;
			}
			else if(b[a[i].da[3].shu]<n/2){
				b[a[i].da[3].shu]++;
				sum+=a[i].da [3].hao;
			}
		}
		maxn=max(maxn,sum);
		sum=0;
		b[1]=b[2]=b[3]=0;
		for(int i=n;i>=1;i--){
			if(b[a[i].da[1].shu]<n/2){
				b[a[i].da[1].shu]++;
				sum+=a[i].da [1].hao;
			}
			else if(b[a[i].da[2].shu]<n/2){
				b[a[i].da[2].shu]++;
				sum+=a[i].da [2].hao;
			}
			else if(b[a[i].da[3].shu]<n/2){
				b[a[i].da[3].shu]++;
				sum+=a[i].da [3].hao;
			}
		}
		maxn=max(maxn,sum);
		cout<<sum<<"\n";
	}
	return 0;
}