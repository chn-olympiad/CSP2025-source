#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct node{
	int bu[5];
	int first,second;
}a[N];
struct info{
	int id,cha;
}f[N];
bool cmp(info c,info d){
	return c.cha>d.cha;
}
int club[10];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		club[1]=n/2,club[2]=n/2,club[3]=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].bu[1]>>a[i].bu[2]>>a[i].bu[3];
			f[i].id=i;
			if(a[i].bu[1]>=a[i].bu[2]&&a[i].bu[1]>=a[i].bu[3]){
				a[i].first=1;
				if(a[i].bu[2]>=a[i].bu[3]){a[i].second=2;f[i].cha=a[i].bu[1]-a[i].bu[2];}
				else{a[i].second=3;f[i].cha=a[i].bu[1]-a[i].bu[3];}
			}
			else if(a[i].bu[2]>=a[i].bu[1]&&a[i].bu[2]>=a[i].bu[3]){
				a[i].first=2;
				if(a[i].bu[1]>=a[i].bu[3]){a[i].second=1;f[i].cha=a[i].bu[2]-a[i].bu[1];}
				else{a[i].second=3;f[i].cha=a[i].bu[2]-a[i].bu[3];}
			}
			else{
				a[i].first=3;
				if(a[i].bu[1]>=a[i].bu[2]){a[i].second=1;f[i].cha=a[i].bu[3]-a[i].bu[1];}
				else{a[i].second=2;f[i].cha=a[i].bu[3]-a[i].bu[2];}
			}
		}
		sort(f+1,f+n+1,cmp);
		for(int i=1;i<=n;i++){
			int j=f[i].id;
			if(club[a[j].first]>=1){
				club[a[j].first]--;
				ans=ans+a[j].bu[a[j].first];
			}
			else{
				club[a[j].second]--;
				ans=ans+a[j].bu[a[j].second];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
