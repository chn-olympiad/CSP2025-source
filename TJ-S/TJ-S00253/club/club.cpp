#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
struct club{
	long long a,b,c;
}a[N];
long long f[N]={};
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,maxn,sum=0,cnt1=0,cnt2=0,cnt3=0;
	cin>>n;
	while(n--){
		long long m;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		for(int i=1;i<=m;i++){
			maxn=max(max(a[i].a,a[i].b),a[i].c);
			if(maxn==a[i].a) cnt1++;
			else if(maxn==a[i].b) cnt2++;
			else cnt3++;
		}
		for(int i=1;i<=m;i++){
			if(cnt1<=m/2&&cnt2<=m/2&&cnt3<=m/2){
				f[i]=max(max(a[i].a,a[i].b),a[i].c);
				sum+=f[i];
			}
			else if(cnt1>m/2&&cnt2<=m/2&&cnt3<=m/2){
				f[i]=max(a[i].b,a[i].c);
				sum+=f[i];
			}
			else if(cnt1<=m/2&&cnt2>m/2&&cnt3<=m/2){
				f[i]=max(a[i].a,a[i].c);
				sum+=f[i];
			}
			else if(cnt1<=m/2&&cnt2<=m/2&&cnt3>m/2){
				f[i]=max(a[i].b,a[i].a);
				sum+=f[i];
			}
			else if(cnt1>m/2&&cnt2>m/2&&cnt3<=m/2){
				f[i]=a[i].c;
				sum+=f[i];
			}
			else if(cnt1>m/2&&cnt2<=m/2&&cnt3>m/2){
				f[i]=a[i].b;
				sum+=f[i];
			}
			else if(cnt1<=m/2&&cnt2>m/2&&cnt3>m/2){
				f[i]=a[i].a;
				sum+=f[i];
			}
			else{
				f[i]=0;
				sum+=f[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
