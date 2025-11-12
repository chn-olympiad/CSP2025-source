#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,to[5],ans;
struct A{
	int c1,c2,c3;
}a[100010];
priority_queue<int>q1,q2,q3,q4;
bool cmp(A x,A y){
	return max(x.c3,max(x.c1,x.c2))>max(y.c3,max(y.c1,y.c2));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		q1.push(-1e15);q2.push(-1e15);q3.push(-1e15);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		sort(a+1,a+n+1,cmp);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(to[1]>=n/2||to[2]>=n/2||to[3]>=n/2){
				cnt=i;
				break;
			}
			if(a[i].c1>=a[i].c2&&a[i].c1>=a[i].c3){
				ans+=a[i].c1;
				to[1]++;
				q2.push(a[i].c2-a[i].c1);
				q3.push(a[i].c3-a[i].c1);
			}else if(a[i].c2>=a[i].c1&&a[i].c2>=a[i].c3){
				ans+=a[i].c2;
				to[2]++;
				q1.push(a[i].c1-a[i].c2);
				q3.push(a[i].c3-a[i].c2);
			}else if(a[i].c3>=a[i].c1&&a[i].c3>=a[i].c2){
				ans+=a[i].c3;
				to[3]++;
				q1.push(a[i].c1-a[i].c3);
				q2.push(a[i].c2-a[i].c3);
			}
		}
		if(!cnt){
			cout<<ans<<"\n";
			ans=0;
			to[1]=to[2]=to[3]=0;
			q1=q4,q2=q4,q3=q4;
			continue;
		}
		int x;
		for(int i=cnt;i<=n;i++){
			if(to[1]>=n/2){
				if(q2.top()+a[i].c1>a[i].c2&&q2.top()>q3.top()&&q2.top()+a[i].c1>a[i].c3){
					ans+=q2.top()+a[i].c1;
					q2.pop();
				}else if(q3.top()+a[i].c1>a[i].c3&&q3.top()>q2.top()&&q3.top()+a[i].c1>a[i].c2){
					ans+=q3.top()+a[i].c1;
					q3.pop();
				}else if(a[i].c2>a[i].c3){
					ans+=a[i].c2;
				}else{
					ans+=a[i].c3;
				}
			}else if(to[2]>=n/2){
				if(q1.top()+a[i].c2>a[i].c1&&q1.top()>q3.top()&&q1.top()+a[i].c2>a[i].c3){
					ans+=q1.top()+a[i].c2;
					q1.pop();
				}else if(q3.top()+a[i].c2>a[i].c3&&q3.top()>q1.top()&&q3.top()+a[i].c2>a[i].c3){
					ans+=q3.top()+a[i].c2;
					q3.pop();
				}else if(a[i].c1>a[i].c3){
					ans+=a[i].c1;
				}else{
					ans+=a[i].c3;
				}
			}else{
				if(q1.top()+a[i].c3>a[i].c1&&q1.top()>q2.top()&&q1.top()+a[i].c3>a[i].c2){
					ans+=q1.top()+a[i].c3;
					q1.pop();
				}else if(q2.top()+a[i].c3>a[i].c1&&q2.top()>q1.top()&&q2.top()+a[i].c3>a[i].c2){
					ans+=q2.top()+a[i].c3;
					q2.pop();
				}else if(a[i].c1>a[i].c2){
					ans+=a[i].c1;
				}else{
					ans+=a[i].c2;
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
		to[1]=to[2]=to[3]=0;
		q1=q4,q2=q4,q3=q4;
	}
	return 0;
} 
