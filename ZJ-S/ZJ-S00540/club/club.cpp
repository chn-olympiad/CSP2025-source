#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
long long rsy[N][4];
long long kkk[N];
long long ans=0;
int n;
struct rensy{
	long long i,x,y,z,sum;
	
};
void bfs(){
	ans=0;
	queue<rensy> q;
	rensy a;
	//a={1,0,0,1,rsy[3]}
	a.i=1;
	a.x=0;
	a.y=0;
	a.z=1;
	a.sum=rsy[1][3];
	q.push(a);
	a.i=1;
	a.x=0;
	a.y=1;
	a.z=0;
	a.sum=rsy[1][2];
	q.push(a);
	a.i=1;
	a.x=1;
	a.y=0;
	a.z=0;
	a.sum=rsy[1][1];
	q.push(a);
	while(!q.empty()){
		rensy cur;
		//printf("%d %d %d %d %d\n",cur.i,cur.x,cur.y,cur.z,cur.sum);
		cur=q.front();
		q.pop();
		int nw=cur.i+1;
		ans=max(ans,cur.sum);
		for(int j=1;j<=3;j++){
			rensy nxt=cur;
			nxt.i+=1;
			if(j==1){
				nxt.x+=1;
				nxt.sum+=rsy[nw][j];
				if(nxt.x<=n/2 && nxt.y<=n/2 && nxt.z<=n/2 && nw<=n){
					q.push(nxt);
				}
			}else if(j==2){
				nxt.y+=1;
				nxt.sum+=rsy[nw][j];
				if(nxt.x<=n/2 && nxt.y<=n/2 && nxt.z<=n/2 && nw<=n){
					q.push(nxt);
				}
			}else{
				nxt.z+=1;
				nxt.sum+=rsy[nw][j];
				if(nxt.x<=n/2 && nxt.y<=n/2 && nxt.z<=n/2 && nw<=n){
					q.push(nxt);
				}
			}
			nxt=cur;
			nxt.i++;
			if(nxt.i<=n){
				q.push(nxt);
			}
		}
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		scanf("%d",&n);
		bool f=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&rsy[i][1],&rsy[i][2],&rsy[i][3]);
			if(rsy[i][2] != 0 || rsy[i][3]!=0) f=0;
		}
		if(f){
			for(int i=1;i<=n;i++){
				kkk[i]=rsy[i][1];
			}
			sort(kkk+1,kkk+1+n);
			for(int i=n;i>=n/2;i--){
				ans+=kkk[i];
			}
		}else{
			bfs();
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}
