#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n,num[10];
long long ans;
struct stu{
	int cha,id;
	pair<int,int> myd[5];
}a[N];
bool cmp(stu a,stu b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].myd[1].first,&a[i].myd[2].first,&a[i].myd[3].first);
			a[i].myd[1].second=1;a[i].myd[2].second=2;a[i].myd[3].second=3;
			if(a[i].myd[3].first<a[i].myd[2].first) swap(a[i].myd[2],a[i].myd[3]);
			if(a[i].myd[2].first<a[i].myd[1].first) swap(a[i].myd[2],a[i].myd[1]);
			if(a[i].myd[3].first<a[i].myd[2].first) swap(a[i].myd[2],a[i].myd[3]);
			a[i].cha=a[i].myd[3].first-a[i].myd[2].first;
			a[i].id=a[i].myd[3].second;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(num[1]>=n/2||num[2]>=n/2||num[3]>=n/2){
				for(int j=i;j<=n;j++){
					if(num[a[j].id]<n/2) ans+=a[j].myd[3].first;
					else ans+=a[j].myd[2].first;
				}
				break;
			}
			ans+=a[i].myd[3].first;
			num[a[i].id]++;
		}
		cout<<ans<<"\n";
		num[1]=num[2]=num[3]=0;
		ans=0;
	}
	return 0;
}
