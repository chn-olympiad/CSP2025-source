#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct node{
	long long x,y,z;
}a[100005];
bool cmp(node xx,node yy){
	long long aa1,bb1,aa2,bb2;
	if(xx.x>=xx.y&&xx.x>=xx.z){
		aa1=xx.x;
		if(xx.y<=xx.x&&xx.y>=xx.z){
			bb1=xx.y;
		}
		else{
			bb1=xx.z;
		}
	}
	else if(xx.y>=xx.x&&xx.y>=xx.z){
		aa1=xx.y;
		if(xx.x<=xx.y&&xx.x>=xx.z){
			bb1=xx.x;
		}
		else{
			bb1=xx.z;
		}
	}
	else{
		aa1=xx.z;
		if(xx.x<=xx.z&&xx.x>=xx.y){
			bb1=xx.x;
		}
		else{
			bb1=xx.y;
		}
	}
	
	if(yy.x>=yy.y&&yy.x>=yy.z){
		aa2=yy.x;
		if(yy.y<=yy.x&&yy.y>=yy.z){
			bb2=yy.y;
		}
		else{
			bb2=yy.z;
		}
	}
	else if(yy.y>=yy.x&&yy.y>=yy.z){
		aa2=yy.y;
		if(yy.x<=yy.y&&yy.x>=yy.z){
			bb2=yy.x;
		}
		else{
			bb2=yy.z;
		}
	}
	else{
		aa2=yy.z;
		if(yy.x<=yy.z&&yy.x>=yy.y){
			bb2=yy.x;
		}
		else{
			bb2=yy.y;
		}
	}
	return (aa1-bb1)>(aa2-bb2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		long long ans=0;
		scanf("%lld",&n);
		long long c1=n/2,c2=n/2,c3=n/2;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			long long num=min(a[i].x,min(a[i].y,a[i].z));
			a[i].x-=num;
			a[i].y-=num;
			a[i].z-=num;
			ans+=num;
		}
		sort(a+1,a+n+1,cmp);
//		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
//			cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
			priority_queue<pair<long long,long long> >pq;
			pq.push(make_pair(a[i].x,1));
			pq.push(make_pair(a[i].y,2));
			pq.push(make_pair(a[i].z,3));
			while(pq.size()){
				pair<long long,long long> tp=pq.top();
				if(tp.second==1){
					if(c1){
						c1--;
						ans+=a[i].x;
						break;
					}
				}
				if(tp.second==2){
					if(c2){
						c2--;
						ans+=a[i].y;
						break;
					}
				}
				if(tp.second==3){
					if(c3){
						c3--;
						ans+=a[i].z;
						break;
					}
				}
				pq.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
