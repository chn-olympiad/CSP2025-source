#include<bits/stdc++.h>
#include<stack>
using namespace std;
long long n,m,k,cnt=0;
long long cnt2=0,ans=0;
long long w[2000010],nex[2000010],poi[10050],v[2000010],hd[2000010];
long long c[21],a[21][10010];
bool vis1[21],vis[10050];
stack<int>q2;
deque<int>q1;
void add_edge(int x,int y,int ww){
	cnt++;
	hd[cnt]=x;v[cnt]=y;nex[cnt]=poi[x];poi[x]=cnt;w[cnt]=ww;
}
void oper(long long beg){
	for(int i=poi[beg];i!=0;i=nex[i]){
			if(!vis[v[i]]){
				while((!q1.empty())&&w[q1.back()]>w[i]){
					q2.push(q1.back());
					q1.pop_back();
				}
				while((!q2.empty())&&w[q2.top()]<w[i]){
					q1.push_back(q2.top());
					q2.pop();
				}
				q1.push_back(i);
			}
		}while(!q2.empty()){
					q1.push_back(q2.top());
					q2.pop();
				}
}
void kruskal(){
	cnt2=1;//set cnt2
	vis[1]=true;
	oper(1);
	while(cnt2!=n){
		if(!q1.empty())
		while(vis[v[q1.front()]]==true){
			q1.pop_front();
		}
		long long beeg=2147483646;
		int pt1=0,pt2=0,pt3=0;
		int u;u=q1.front();
		for(int i=1;i<=k;i++){
			if(!vis1[i]){
				for(int j=1;j<=n;j++){
					if(!vis[j]){
						for(int l=1;l<=n;l++){
							if(vis[l]){
								if(beeg>a[i][l]+a[i][j]+c[i]){
									beeg=a[i][l]+a[i][j]+c[i];
									pt1=i;pt2=j;pt3=l;
								}
							}
						}
						
					}
				}
			}
		}
		if(w[u]<beeg){
//			cout<<1<<" "<<w[u]<<" "<<hd[u]<<" "<<v[u]<<endl;
			vis[v[u]]=true;
			cnt2++;
			ans+=w[u];
			q1.pop_front();
			oper(v[u]);
//			for(int i=1;i<=n+k;i++)cout<<vis[i]<<" ";cout<<endl;
		}
		else{
//			cout<<2<<" "<<pt1<<" "<<pt2<<" "<<pt3<<endl;
			cnt2++;
			ans+=beeg;
			vis[n+pt1]=1;
			vis[pt2]=1;vis1[pt1]=1;vis[pt3]=1;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					add_edge(pt1+n,i,a[pt1][i]);
					add_edge(i,pt1+n,a[pt1][i]);
				}
			}
			oper(n+pt1);
			oper(pt2);
//			for(int i=1;i<=n+k;i++)cout<<vis[i]<<" ";cout<<endl;
		}
	}		
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,ww;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>ww;
		add_edge(x,y,ww);
		add_edge(y,x,ww);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	kruskal();
	cout<<ans<<endl;
	return 0;
}
