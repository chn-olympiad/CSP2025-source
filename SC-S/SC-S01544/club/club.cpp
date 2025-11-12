#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int _t,n,maxn[100010];
bool vis[100010];
priority_queue<pii,vector<pii>,greater<pii> >q1,q2,q3;
struct aaa{
	int a1,a2,a3;
}a[100010];
bool cmp1(aaa x,aaa b){
	if(x.a1!=b.a1)
		return x.a1>b.a1;
	if(max(x.a2,x.a3)!=max(b.a2,b.a3))
		return max(x.a2,x.a3)<max(b.a2,b.a3);
	return x.a2+x.a3<b.a2+b.a3;
}
bool cmp2(aaa x,aaa b){
	if(x.a2!=b.a2)
		return x.a2>b.a2;
	if(max(x.a1,x.a3)!=max(b.a1,b.a3))
		return max(x.a1,x.a3)<max(b.a1,b.a3);
	return x.a1+x.a3<b.a1+b.a3;
}
bool cmp3(aaa x,aaa b){
	if(x.a3!=b.a3)
		return x.a3>b.a3;
	if(max(x.a1,x.a2)!=max(b.a1,b.a2))
		return max(x.a1,x.a2)<max(b.a1,b.a2);
	return x.a1+x.a2<b.a1+b.a2;
}
bool cmp11(aaa x,aaa b){
	if(x.a1!=b.a1)
		return x.a1<b.a1;
	if(max(x.a2,x.a3)!=max(b.a2,b.a3))
		return max(x.a2,x.a3)<max(b.a2,b.a3);
	return x.a2+x.a3<b.a2+b.a3;
}
bool cmp22(aaa x,aaa b){
	if(x.a2!=b.a2)
		return x.a2<b.a2;
	if(max(x.a1,x.a3)!=max(b.a1,b.a3))
		return max(x.a1,x.a3)<max(b.a1,b.a3);
	return x.a1+x.a3<b.a1+b.a3;
}
bool cmp33(aaa x,aaa b){
	if(x.a3!=b.a3)
		return x.a3<b.a3;
	if(max(x.a1,x.a2)!=max(b.a1,b.a2))
		return max(x.a1,x.a2)<max(b.a1,b.a2);
	return x.a1+x.a2<b.a1+b.a2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&_t);
	while(_t--){
		int ans=-1;
		scanf("%lld",&n);
		int minn=n/3;
		if(n%3)
			minn++;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
		sort(a+1,a+1+n,cmp1);
		for(int i=minn;i<=n/2;i++){
			int anss=0;
			while(!q2.empty()) q2.pop();
			while(!q3.empty()) q3.pop();
			for(int j=1;j<=n;j++){
				if(j<=i){
					anss+=a[j].a1;
					continue;
				}
				if(a[j].a2==a[j].a3)
					anss+=a[j].a2;
				else{
					if(a[j].a2>a[j].a3){
						if(q2.size()<n/2)
							q2.push(make_pair(a[j].a2,j));
						else{
//							if(q2.top().first<a[j].a2){
//								int id=q2.top().second;
//								q3.push(make_pair(a[id].a3,id));
//								q2.pop();
//								q2.push(make_pair(a[j].a2,j));
//							}
//							else
								q3.push(make_pair(a[j].a3,j));
						}
					}
					else{
						if(q3.size()<n/2)
							q3.push(make_pair(a[j].a3,j));
						else{
//							if(q3.top().first<a[j].a3){
//								int id=q3.top().second;
//								q2.push(make_pair(a[id].a2,id));
//								q3.pop();
//								q3.push(make_pair(a[j].a3,j));
//							}
//							else
								q2.push(make_pair(a[j].a2,j));
						}
					}
				}
			}
			while(!q2.empty()){
				anss+=q2.top().first;
				q2.pop();
			}
			while(!q3.empty()){
				anss+=q3.top().first;
				q3.pop();
			}
			ans=max(ans,anss);
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=minn;i<=n/2;i++){
			int anss=0;
			while(!q1.empty()) q1.pop();
			while(!q3.empty()) q3.pop();
			for(int j=1;j<=n;j++){
				if(j<=i){
					anss+=a[j].a2;
					continue;
				}
				if(a[j].a1==a[j].a3)
					anss+=a[j].a1;
				else{
					if(a[j].a1>a[j].a3){
						if(q1.size()<n/2)
							q1.push(make_pair(a[j].a1,j));
						else{
//							if(q1.top().first<a[j].a1){
//								int id=q1.top().second;
//								q3.push(make_pair(a[id].a3,id));
//								q1.pop();
//								q1.push(make_pair(a[j].a1,j));
//							}
//							else
								q3.push(make_pair(a[j].a3,j));
						}
					}
					else{
						if(q3.size()<n/2)
							q3.push(make_pair(a[j].a3,j));
						else{
//							if(q3.top().first<a[j].a3){
//								int id=q3.top().second;
//								q1.push(make_pair(a[id].a1,id));
//								q3.pop();
//								q3.push(make_pair(a[j].a3,j));
//							}
//							else
								q1.push(make_pair(a[j].a1,j));
						}
					}
				}
			}
			while(!q1.empty()){
				anss+=q1.top().first;
				q1.pop();
			}
			while(!q3.empty()){
				anss+=q3.top().first;
				q3.pop();
			}
			ans=max(ans,anss);
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=minn;i<=n/2;i++){
			int anss=0;
			while(!q2.empty()) q2.pop();
			while(!q1.empty()) q1.pop();
			for(int j=1;j<=n;j++){
				if(j<=i){
					anss+=a[j].a3;
					continue;
				}
				if(a[j].a2==a[j].a1)
					anss+=a[j].a2;
				else{
					if(a[j].a2>a[j].a1){
						if(q2.size()<n/2)
							q2.push(make_pair(a[j].a2,j));
						else{
//							if(q2.top().first<a[j].a2){
//								int id=q2.top().second;
//								q1.push(make_pair(a[id].a1,id));
//								q2.pop();
//								q2.push(make_pair(a[j].a2,j));
//							}
//							else
								q1.push(make_pair(a[j].a1,j));
						}
					}
					else{
						if(q1.size()<n/2)
							q1.push(make_pair(a[j].a1,j));
						else{
//							if(q1.top().first<a[j].a1){
//								int id=q1.top().second;
//								q2.push(make_pair(a[id].a2,id));
//								q1.pop();
//								q1.push(make_pair(a[j].a1,j));
//							}
//							else
								q2.push(make_pair(a[j].a2,j));
						}
					}
				}
			}
			while(!q2.empty()){
				anss+=q2.top().first;
				q2.pop();
			}
			while(!q1.empty()){
				anss+=q1.top().first;
				q1.pop();
			}
			ans=max(ans,anss);
		}
		sort(a+1,a+1+n,cmp11);
		for(int i=minn;i<=n/2;i++){
			int anss=0;
			while(!q2.empty()) q2.pop();
			while(!q3.empty()) q3.pop();
			for(int j=1;j<=n;j++){
				if(j<=i){
					anss+=a[j].a1;
					continue;
				}
				if(a[j].a2==a[j].a3)
					anss+=a[j].a2;
				else{
					if(a[j].a2>a[j].a3){
						if(q2.size()<n/2)
							q2.push(make_pair(a[j].a2,j));
						else{
//							if(q2.top().first<a[j].a2){
//								int id=q2.top().second;
//								q3.push(make_pair(a[id].a3,id));
//								q2.pop();
//								q2.push(make_pair(a[j].a2,j));
//							}
//							else
								q3.push(make_pair(a[j].a3,j));
						}
					}
					else{
						if(q3.size()<n/2)
							q3.push(make_pair(a[j].a3,j));
						else{
//							if(q3.top().first<a[j].a3){
//								int id=q3.top().second;
//								q2.push(make_pair(a[id].a2,id));
//								q3.pop();
//								q3.push(make_pair(a[j].a3,j));
//							}
//							else
								q2.push(make_pair(a[j].a2,j));
						}
					}
				}
			}
			while(!q2.empty()){
				anss+=q2.top().first;
				q2.pop();
			}
			while(!q3.empty()){
				anss+=q3.top().first;
				q3.pop();
			}
			ans=max(ans,anss);
		}
		sort(a+1,a+1+n,cmp22);
		for(int i=minn;i<=n/2;i++){
			int anss=0;
			while(!q1.empty()) q1.pop();
			while(!q3.empty()) q3.pop();
			for(int j=1;j<=n;j++){
				if(j<=i){
					anss+=a[j].a2;
					continue;
				}
				if(a[j].a1==a[j].a3)
					anss+=a[j].a1;
				else{
					if(a[j].a1>a[j].a3){
						if(q1.size()<n/2)
							q1.push(make_pair(a[j].a1,j));
						else{
//							if(q1.top().first<a[j].a1){
//								int id=q1.top().second;
//								q3.push(make_pair(a[id].a3,id));
//								q1.pop();
//								q1.push(make_pair(a[j].a1,j));
//							}
//							else
								q3.push(make_pair(a[j].a3,j));
						}
					}
					else{
						if(q3.size()<n/2)
							q3.push(make_pair(a[j].a3,j));
						else{
//							if(q3.top().first<a[j].a3){
//								int id=q3.top().second;
//								q1.push(make_pair(a[id].a1,id));
//								q3.pop();
//								q3.push(make_pair(a[j].a3,j));
//							}
//							else
								q1.push(make_pair(a[j].a1,j));
						}
					}
				}
			}
			while(!q1.empty()){
				anss+=q1.top().first;
				q1.pop();
			}
			while(!q3.empty()){
				anss+=q3.top().first;
				q3.pop();
			}
			ans=max(ans,anss);
		}
		sort(a+1,a+1+n,cmp33);
		for(int i=minn;i<=n/2;i++){
			int anss=0;
			while(!q2.empty()) q2.pop();
			while(!q1.empty()) q1.pop();
			for(int j=1;j<=n;j++){
				if(j<=i){
					anss+=a[j].a3;
					continue;
				}
				if(a[j].a2==a[j].a1)
					anss+=a[j].a2;
				else{
					if(a[j].a2>a[j].a1){
						if(q2.size()<n/2)
							q2.push(make_pair(a[j].a2,j));
						else{
//							if(q2.top().first<a[j].a2){
//								int id=q2.top().second;
//								q1.push(make_pair(a[id].a1,id));
//								q2.pop();
//								q2.push(make_pair(a[j].a2,j));
//							}
//							else
								q1.push(make_pair(a[j].a1,j));
						}
					}
					else{
						if(q1.size()<n/2)
							q1.push(make_pair(a[j].a1,j));
						else{
//							if(q1.top().first<a[j].a1){
//								int id=q1.top().second;
//								q2.push(make_pair(a[id].a2,id));
//								q1.pop();
//								q1.push(make_pair(a[j].a1,j));
//							}
//							else
								q2.push(make_pair(a[j].a2,j));
						}
					}
				}
			}
			while(!q2.empty()){
				anss+=q2.top().first;
				q2.pop();
			}
			while(!q1.empty()){
				anss+=q1.top().first;
				q1.pop();
			}
			ans=max(ans,anss);
		}
		printf("%lld\n",ans);
	}
	return 0;
}