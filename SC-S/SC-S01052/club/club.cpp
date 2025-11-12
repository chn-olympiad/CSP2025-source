#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1e5+10;

int T,n,a[N][4];

int main(){
	#ifndef Klein
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt1++,sum+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt2++,sum+=a[i][2];
			else cnt3++,sum+=a[i][3];
		}
		if(max({cnt1,cnt2,cnt3})<=n/2){
			cout<<sum<<'\n';
			continue;
		}
		int opt=cnt1>n/2?1:(cnt2>n/2?2:3),cnt=0,ans=0;
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(opt!=1) ans+=a[i][1];
				else{
					if(cnt<n/2){
						ans+=a[i][1],cnt++;
						q.push(-a[i][1]+max(a[i][2],a[i][3]));
					}
					else{
						if(max(a[i][2],a[i][3])>a[i][1]+q.top()) ans+=max(a[i][2],a[i][3]);
						else{
							ans+=a[i][1]+q.top(); q.pop();
							q.push(-a[i][1]+max(a[i][2],a[i][3]));
						}
					}
				} 
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				if(opt!=2) ans+=a[i][2];
				else{
					if(cnt<n/2){
						ans+=a[i][2],cnt++;
						q.push(-a[i][2]+max(a[i][1],a[i][3]));
					}
					else{
						if(max(a[i][1],a[i][3])>a[i][2]+q.top()) ans+=max(a[i][1],a[i][3]);
						else{
							ans+=a[i][2]+q.top(); q.pop();
							q.push(-a[i][2]+max(a[i][1],a[i][3]));
						}
					}
				} 
			}
			else{
				if(opt!=3) ans+=a[i][3];
				else{
					if(cnt<n/2){
						ans+=a[i][3],cnt++;
						q.push(-a[i][3]+max(a[i][1],a[i][2]));
					}
					else{
						if(max(a[i][1],a[i][2])>a[i][3]+q.top()) ans+=max(a[i][1],a[i][2]);
						else{
							ans+=a[i][3]+q.top(); q.pop();
							q.push(-a[i][3]+max(a[i][1],a[i][2]));
						}
					}
				} 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
