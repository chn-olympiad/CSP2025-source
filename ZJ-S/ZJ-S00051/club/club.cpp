#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[110000][5],ans,s[110000];
struct pp{
	int num[3]={0,0,0};
	int a,sum;
};
queue<pp> q;
void bfs(){
	for(int i=1;i<=3;i++){
		pp st;
		st.a=1;
		st.sum=a[1][i];
		st.num[i-1]=1;
		q.push(st);
	}
	while(q.size()){
		pp u=q.front();
		if(u.a==n){
			ans=max(ans,u.sum);
		}
		q.pop();
		for(int i=1;i<=3;i++){
			if(u.num[i-1]==n/2) continue;
			pp v=u;
			v.a++;
			v.num[i-1]++;
			v.sum+=a[v.a][i];
			q.push(v);
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		if(n<=10){
			bfs();
			cout<<ans<<endl;
			ans=0;
		}
		else{
			for(int i=1;i<=n;i++){
				s[i]=a[i][1];
			}
			sort(s+1,s+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=s[i];
			}
			cout<<ans;
			ans=0;
		}
	}
}
