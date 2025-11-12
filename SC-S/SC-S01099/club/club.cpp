#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct people{
	int mx,num,id;
	bool operator<(const people &a)const{
		return a.num<num;
	}
}a[N];
bool cmp(people x,people y){
	return x.mx>y.mx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		priority_queue<people>q[4];
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int w1,w2,w3;
			scanf("%lld%lld%lld",&w1,&w2,&w3);
			if(w1>=w2 && w2>=w3){
				a[i]={w1,w1-w2,1};
			}
			else if(w1>=w3 && w3>=w2){
				a[i]={w1,w1-w3,1};
			}
			else if(w2>=w1 && w1>=w3){
				a[i]={w2,w2-w1,2};
			}
			else if(w2>=w3 && w3>=w1){
				a[i]={w2,w2-w3,2};
			}
			else if(w3>=w1 && w1>=w2){
				a[i]={w3,w3-w1,3};
			}
			else if(w3>=w2 && w2>=w1){
				a[i]={w3,w3-w2,3};
			}
			
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].mx<<" "<<a[i].num<<" "<<a[i].id<<endl;
//		}
		int cnt[4]={0,0,0,0};
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].id]<n/2){
				q[a[i].id].push(a[i]);
				cnt[a[i].id]++;
				ans+=a[i].mx;
			}
			else{
				//cout<<"### "<<q.top().num<<endl;
				q[a[i].id].push(a[i]);
				ans+=a[i].mx;
				ans-=q[a[i].id].top().num;
				q[a[i].id].pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
