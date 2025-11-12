#include<bits/stdc++.h>
using namespace std;
int t,n,cnt,cnt1,cnt2,cnt3,a[100005],b[100005],c[100005],d[100005],e[100005];
long long ans;
struct node{
	int f,pos;
}s[100005];
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]){
				if(a[i]>c[i]){
					d[i]=a[i];
					cnt1++;
					if(b[i]>c[i]){
						e[i]=b[i];
					}
					else{
						e[i]=c[i];
					}
				}
				else{
					d[i]=c[i];
					e[i]=a[i];
					cnt3++;
				}
			}
			else{
				if(a[i]>c[i]){
					d[i]=b[i];
					e[i]=a[i];
					cnt2++;
				}
				else{
					if(b[i]>c[i]){
						d[i]=b[i];
						e[i]=c[i];
						cnt2++;
					}
					else{
						d[i]=c[i];
						e[i]=b[i];
						cnt3++;
					}
				}
			}
		}
		int xian=n/2,flag=0;
		if(cnt1>xian){
			flag=1,cnt=0;
			for(int i=1;i<=n;i++){
				if(d[i]==a[i]){
					cnt++;
					s[cnt].f=d[i]-e[i];
					s[cnt].pos=i;
				}
			}
		}
		else if(cnt2>xian){
			flag=1,cnt=0;
			for(int i=1;i<=n;i++){
				if(d[i]==b[i]){
					cnt++;
					s[cnt].f=d[i]-e[i];
					s[cnt].pos=i;
				}
			}
		}
		else if(cnt3>xian){
			flag=1,cnt=0;
			for(int i=1;i<=n;i++){
				if(d[i]==c[i]){
					cnt++;
					s[cnt].f=d[i]-e[i];
					s[cnt].pos=i;
				}
			}
		}
		if(flag==1){
			sort(s+1,s+1+cnt,cmp);
			for(int i=xian+1;i<=cnt;i++){
				d[s[i].pos]=e[s[i].pos];
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=d[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
