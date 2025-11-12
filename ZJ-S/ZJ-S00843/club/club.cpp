#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4];
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,n1,n2,n3,ans;
	cin>>t;
	while(t--){
		ans=0;
		n1=0;
		n2=0;
		n3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(n1<n/2){
					n1++;
					ans+=a[i][1];
					q1.push(a[i][1]-max(a[i][2],a[i][3]));
					continue;
				}else{
					if(q1.top()<=a[i][1]-max(a[i][2],a[i][3])){
						ans-=q1.top();
						q1.pop();
						ans+=a[i][1];
						q1.push(a[i][1]-max(a[i][2],a[i][3]));
						continue;
					}else{
						ans+=max(a[i][2],a[i][3]);
						continue;
					}
				}
			}
			if(a[i][2]>=a[i][3]){
				if(n2<n/2){
					n2++;
					ans+=a[i][2];
					q2.push(a[i][2]-max(a[i][1],a[i][3]));
					continue;
				}else{
					if(q2.top()<=a[i][2]-max(a[i][1],a[i][3])){
						ans-=q2.top();
						q2.pop();
						ans+=a[i][2];
						q2.push(a[i][2]-max(a[i][1],a[i][3]));
						continue;
					}else{
						ans+=max(a[i][1],a[i][3]);
						continue;
					}
				}
			}
			if(n3<n/2){
				n3++;
				ans+=a[i][3];
				q3.push(a[i][3]-max(a[i][1],a[i][2]));
				continue;
			}else{
				if(q3.top()<=a[i][3]-max(a[i][1],a[i][2])){
					ans-=q3.top();
					q3.pop();
					ans+=a[i][3];
					q3.push(a[i][3]-max(a[i][1],a[i][2]));
				}else{
					ans+=max(a[i][1],a[i][2]);
				}
			}
		}
		cout<<ans<<"\n";
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
	}
	return 0;
}
