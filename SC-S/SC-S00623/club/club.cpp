#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
struct node{
	int sa1;
	int sa2;
	int sa3;
}a[N];
bool cmp(node p,node q){
	int i,j;
	i=2*max(max(p.sa1,p.sa2),p.sa3)-p.sa1-p.sa2-p.sa3+min(min(p.sa1,p.sa2),p.sa3);
	j=2*max(max(q.sa1,q.sa2),q.sa3)-q.sa1-q.sa2-q.sa3+min(min(q.sa1,q.sa2),q.sa3);
	if(i>j){
		return true;
	} 
	else if(i<j){
		return false;
	}
	else{
		return max(max(p.sa1,p.sa2),p.sa3)>max(max(q.sa1,q.sa2),q.sa3);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int cnt1=0,cnt2=0,cnt3=0;
		long long ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d %d %d",&a[i].sa1,&a[i].sa2,&a[i].sa3);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(a[i].sa1>a[i].sa2&&a[i].sa1>a[i].sa3){
				if(cnt1<n/2){
					++cnt1;
					ans+=a[i].sa1;
				}
				else{
					if(a[i].sa2>a[i].sa3){
						++cnt2;
						ans+=a[i].sa2;
					}
					else if(a[i].sa2<=a[i].sa3){
						++cnt3;
						ans+=a[i].sa3;
					}
				}
			}
			else if(a[i].sa2>a[i].sa1&&a[i].sa2>a[i].sa3){
				if(cnt2<n/2){
					++cnt2;
					ans+=a[i].sa2;
				}
				else{
					if(a[i].sa1>a[i].sa3){
						++cnt1;
						ans+=a[i].sa1;
					}
					else if(a[i].sa1<=a[i].sa3){
						++cnt3;
						ans+=a[i].sa3;
					}
				}
			}
			else if(a[i].sa3>a[i].sa1&&a[i].sa3>a[i].sa2){
				if(cnt3<n/2){
					++cnt3;
					ans+=a[i].sa3;
				}
				else{
					if(a[i].sa1>a[i].sa2){
						++cnt1;
						ans+=a[i].sa1;
					}
					else if(a[i].sa1<=a[i].sa2){
						++cnt2;
						ans+=a[i].sa2;
					}
				}
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
