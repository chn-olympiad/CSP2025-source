#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
long long n,a[200005],b[200005],c[200005],x[200005],ans=0;
priority_queue<long long,vector<long long>,greater<long long> > q;
void solve(){
	ans=0;
	cin>>n;
	int cnt1=0,cnt2=0,cnt3=0,tmp=0;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i]>>c[i];
		int t=max(a[i],max(b[i],c[i]));
		ans+=t;
		if(a[i]==t){
			x[i]=1;
			cnt1++;
		} 
		else if(b[i]==t){
			x[i]=2;
			cnt2++;
		} 
		else if(c[i]==t){
			x[i]=3;
			cnt3++;
		} 
	}
	if(cnt1>n/2){
		tmp=cnt1;
		for(int i=1; i<=n; i++){
			if(x[i]==1){
				q.push(min(a[i]-b[i],a[i]-c[i]));
			}
		}
	}
	if(cnt2>n/2){
		tmp=cnt2;
		for(int i=1; i<=n; i++){
			if(x[i]==2){
				q.push(min(b[i]-a[i],b[i]-c[i]));
			}
		}
	}
	if(cnt3>n/2){
		tmp=cnt3;
		for(int i=1; i<=n; i++){
			if(x[i]==3){
				q.push(min(c[i]-b[i],c[i]-a[i]));
			}
		}
	}
//	cout<<q.size()<<' '<<tmp<<"!!!!\n";
	while(tmp>n/2){
		tmp--;
		ans-=q.top();
//		cout<<q.top()<<"**\n";
		q.pop();
	}
	cout<<ans<<'\n';
//	cout<<q.size()<<"!!!!\n";
	while(!q.empty()) q.pop();
	memset(x,0,sizeof x);
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cout<<111;
	int T;
	cin>>T;
	while(T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

