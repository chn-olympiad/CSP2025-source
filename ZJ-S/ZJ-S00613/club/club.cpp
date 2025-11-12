#include<bits/stdc++.h>
using namespace std;
int T;
struct student{
	long long a[5];
	long long pt[5];
}p[100010];
struct node{
	long long a,b;
	int t,tk;
	bool operator<(const node& s) const{
		return (b-a)<(s.b-s.a);
	}
};
long long ans=0;
int cnt[5];
int n;
priority_queue<node> club[5];
bool check(int i,int k){
	long long sumn=0;
		if(cnt[p[i].pt[k]]<n/2){
			cnt[p[i].pt[k]]++;
			club[p[i].pt[k]].push({p[i].a[p[i].pt[k]],p[i].a[p[i].pt[k+1]],i,k-1});
			ans+=p[i].a[p[i].pt[k]];
			return 1;
		}else{
			node temp=club[p[i].pt[k]].top();
			if(p[i].a[p[i].pt[k]]>temp.a-temp.b){
				if(temp.tk==0){
					sumn+=p[i].a[p[i].pt[k]]+temp.b;
					sumn-=temp.a;
					if(sumn<p[i].a[p[i].pt[k+1]]) return 0;
					ans+=sumn;
					club[p[i].pt[k]].pop();
					cnt[p[temp.t].pt[2]]++;
					club[p[temp.t].pt[2]].push({p[temp.t].a[p[temp.t].pt[2]],p[temp.t].a[p[temp.t].pt[3]],i,1});
					club[p[i].pt[k]].push({p[i].a[p[i].pt[k]],p[i].a[p[i].pt[k+1]],i,k-1});				
				}
				if(temp.tk==1){
					sumn+=p[i].a[p[i].pt[k]]+temp.b;
					sumn-=temp.a;
					if(sumn<p[i].a[p[i].pt[k+1]]) return 0;
					ans+=sumn;
					club[p[i].pt[k]].pop();
					cnt[p[temp.t].pt[3]]++;
					club[p[i].pt[k]].push({p[i].a[p[i].pt[k]],p[i].a[p[i].pt[k+1]],i,k-1});							
				}
			}
		}	
		if(sumn==0) return 0;
		return 1;
}
void solve(){
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	while(club[1].size()) club[1].pop();
	while(club[2].size()) club[2].pop();
	while(club[3].size()) club[3].pop();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
		if(p[i].a[1]>=p[i].a[2]&&p[i].a[2]>=p[i].a[3]) p[i].pt[1]=1,p[i].pt[2]=2,p[i].pt[3]=3;
		else if(p[i].a[1]>=p[i].a[3]&&p[i].a[3]>=p[i].a[2]) p[i].pt[1]=1,p[i].pt[2]=3,p[i].pt[3]=2;
		else if(p[i].a[2]>=p[i].a[1]&&p[i].a[1]>=p[i].a[3]) p[i].pt[1]=2,p[i].pt[2]=1,p[i].pt[3]=3;
		else if(p[i].a[2]>=p[i].a[3]&&p[i].a[3]>=p[i].a[1]) p[i].pt[1]=2,p[i].pt[2]=3,p[i].pt[3]=1;
		else if(p[i].a[3]>=p[i].a[1]&&p[i].a[1]>=p[i].a[2]) p[i].pt[1]=3,p[i].pt[2]=1,p[i].pt[3]=2;
		else if(p[i].a[3]>=p[i].a[2]&&p[i].a[2]>=p[i].a[1]) p[i].pt[1]=3,p[i].pt[2]=2,p[i].pt[3]=1;
	}
	for(int i=1;i<=n;i++){
		if(check(i,1));
		else check(i,2);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
4 
4 2 1
3 2 4
5 3 4
3 5 1
*/