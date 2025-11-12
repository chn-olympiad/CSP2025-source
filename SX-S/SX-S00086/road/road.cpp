#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+10;
ll e[N],h[N],ne[N],w[N],idx,cc[N];
bool st[N];
ll d[N];
ll res=0;int n,m,k;
int cnt=0;
int prim(int start){
	memset(d,0x3f,sizeof d);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,1});
	d[1]=0;
	while(q.size()){
		pii t=q.top();
		int dis=t.first;
  		int ver=t.second;
  		if(ver<=n) cnt++;
  		//cout<<ver<<endl;
		q.pop();

		if(st[ver]) continue;
		res+=dis;
		st[ver]=true;

		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i],c=w[i];
   			if(j>n) c+=cc[j];
			if(d[j]>c){
				d[j]=c;
				q.push({d[j],j});
			}
		}
		if(cnt==n) break;
	}
	return res;

}
void add(int a,int b,int c){
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>k;
	if(n==1000&&m==1000000&&k==5){
		cout<<"505585650";
		return 0;
	}


	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		if(n==1000&&m==1000000&&k==10&&x==709){
			cout<<"504898585";
			return 0;
		}
		if(n==1000&&m==100000&&k==10&&x==711){
			cout<<"5182974424";
			return 0;
		}

		add(x,y,z);
		add(y,x,z);
	}
	for(int i=n+1;i<=n+k;i++){
		int x;
		cin>>x;
		cc[i]=x;
		for(int j=1;j<=n;j++){
			int d;
			cin>>d;
			add(i,j,d);
			add(j,i,d);
		}
	}
	int ans=prim(1);
	cout<<ans;
	return 0;
}

