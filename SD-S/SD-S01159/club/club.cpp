#include<bits/stdc++.h>
using namespace std;
int p,n;
struct cl{
	long long a;long long b;
}k1[100100],k2[100100],k3[100100];
long long m[100100][4];
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>p;
	for(int l=1;l<=p;l++){
		cin>>n;
		long long ans=0;
		long long cnt1=0,cnt2=0,cnt3=0;
		while(!q.empty()){
			q.pop();
		}
		memset(k1,0,sizeof(k1));
		memset(k2,0,sizeof(k2));
		memset(k3,0,sizeof(k3));
		memset(m,0,sizeof(m));
		for(int i=1;i<=n;i++){
			cin>>m[i][1]>>m[i][2]>>m[i][3];
			if(m[i][1]>=m[i][2]&&m[i][1]>=m[i][3]){
				ans+=m[i][1];
				cnt1++;
				k1[cnt1].a=m[i][1];
				k1[cnt1].b=i;
			}
			else if(m[i][2]>=m[i][1]&&m[i][2]>=m[i][3]){
				ans+=m[i][2];
				cnt2++;
				k2[cnt2].a=m[i][2];
				k2[cnt2].b=i;
			}
			else if(m[i][3]>=m[i][2]&&m[i][3]>=m[i][1]){
				ans+=m[i][3];
				cnt3++;
				k3[cnt3].a=m[i][3];
				k3[cnt3].b=i;
			}
		}
		if(cnt1>n/2){
			for(int j=1;j<=cnt1;j++){
				q.push(m[k1[j].b][1]-max(m[k1[j].b][2],m[k1[j].b][3]));
			}
			while(cnt1>n/2){
				ans-=q.top();
				q.pop();
				cnt1--;
			}
	}
		else if(cnt2>n/2){
			for(int j=1;j<=cnt2;j++){
				q.push(m[k2[j].b][2]-max(m[k2[j].b][1],m[k2[j].b][3]));
			}
			while(cnt2>n/2){
				ans-=q.top();
				q.pop();
				cnt2--;
			}
		}
		else if(cnt3>n/2){
			for(int j=1;j<=cnt3;j++){
				q.push(m[k3[j].b][3]-max(m[k3[j].b][1],m[k3[j].b][2]));
			}
			while(cnt3>n/2){
				ans-=q.top();
				q.pop();
				cnt3--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
