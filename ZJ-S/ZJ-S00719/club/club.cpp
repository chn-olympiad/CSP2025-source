#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll v,i;
}t[4][100055];
bool cmp(node a,node b){
	return a.v<b.v;
}
ll T,n,d[4][100055],ans,tot;
void solve(int a,int b,int c,int res){
	unordered_map<int,bool> mp;
	for(int i=n/2+1;i<=n;i++) mp[t[a][i].i]=1;
	int i=n,j=n,cnt=0;
	while(cnt<n/2){
		if(mp[t[b][i].i]==1) i--;
		if(mp[t[c][j].i]==1) j--;
		if(t[b][i].v>t[c][j].v){
			res+=t[b][i].v;
			i--;
		}else{
			res+=t[c][j].v;
			j--;
		}
	//	cout<<res<<" ";
		cnt++;
	}
	ans=res;
}
int main(){
	freopen("club2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		int s1=0,s2=0,s3=0,ma1=0,ma2=0,ma3=0;
		for(int i=1;i<=n;i++){
			cin>>d[1][i]>>d[2][i]>>d[3][i];
			s1+=d[1][i];s2+=d[2][i];s3+=d[3][i];
			t[1][i].v=d[1][i];t[2][i].v=d[2][i];t[3][i].v=d[3][i];
			t[1][i].i=i;t[2][i].i=i;t[3][i].i=i;
		}
		sort(t[1]+1,t[1]+1+n,cmp);
		sort(t[2]+1,t[2]+1+n,cmp);
		sort(t[3]+1,t[3]+1+n,cmp);
		for(int i=n/2+1;i<=n;i++) ma1+=t[1][i].v; 
		for(int i=n/2+1;i<=n;i++) ma2+=t[2][i].v;
		for(int i=n/2+1;i<=n;i++) ma3+=t[3][i].v; 
		double k1=ma1-s1/2,k2=ma2-s2/2,k3=ma3-s3/2;
		if(k1>k2&&k1>k3) solve(1,2,3,ma1);
		else if(k2>k1&&k2>k3) solve(2,1,3,ma2);
		else if(k3>k1&&k3>k1) solve(3,2,1,ma3);
		else{
			if(s1>=s2&&s1>=s3) solve(1,2,3,ma1);
			else if(s2>=s1&&s2>=s3) solve(2,1,3,ma2);
			else solve(3,2,1,ma3);
		} 
	//	cout<<k1<<" "<<k2<<" "<<k3<<endl;
		cout<<ans<<endl;
	}
	return 0;
}