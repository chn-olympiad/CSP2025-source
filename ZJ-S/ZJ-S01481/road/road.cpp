#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=1e4+30;
const int MAXK=12;
priority_queue<pair<ll,int> >q;
vector<pair<ll,int> >road[MAX];
vector<pair<ll,int> >to_road[MAX];
int n,m,k;
//pair first=w,second=to

pair<ll,int>newr[MAXK][MAX];
ll adds[MAXK];

void printq(){
	//this operator can clear queue
	cout<<endl<<"q"<<endl;
	while(!q.empty()){
		printf("%3d %lld\n",q.top().second,q.top().first);
		q.pop();
	}
}
void print(){
	printf("now_road:\n");
	for(int i=1;i<=n;i++){
		printf("\n%d\n",i);
		for(int j=0;j<to_road[i].size();j++){
			printf("%3d %lld\n",to_road[i][j].second,to_road[i][j].first);
		}
	}
	printf("\n\n\nnewr:\n");
	for(int i=0;i<k;i++){
		printf("\n%d\n",i);
		for(int j=1;j<=n;j++){
			printf("%3d %lld\n",newr[i][j].second,newr[i][j].first);
		}
	}
	cout<<endl<<endl;
}

void copy_old_road(){
	for(int i=1;i<=n;i++){
		to_road[i].clear();
		for(int j=0;j<road[i].size();j++){
			to_road[i].push_back(road[i][j]);
		}
	}
}

int lowbit(int bin){return bin&(-bin);}
pair<int,ll> make_new_road(int bin){//first is add_node_num second is sumw
	//cout<<"!"<<newr
	//cout<<"bin:"<<bin<<endl;
	ll sumw=0;
	copy_old_road();
	int cnt=1;
	while(bin){
		int bins=log2(lowbit(bin));
		bin-=(1<<bins);
		sumw+=adds[bins];
		//bins++;
		//cout<<bins<<endl;
		//
		for(int j=1;j<=n;j++){//n+cnt is add node
			//print();
			//cout<<endl<<"newr[1]["<<j<<"]:"<<newr[bins][j].first<<endl;
			to_road[n+cnt].push_back(newr[bins][j]);
			to_road[newr[bins][j].second].push_back(make_pair(newr[bins][j].first,n+cnt));
		}
		cnt++;
		//cout<<bins;
		//print();
	}
	//cout<<"cnt:"<<cnt<<endl;
	return make_pair(cnt-1,sumw);// because many
}

ll solve(int size){
	ll ans=0;
	while(!q.empty()) q.pop();
	//q.clear();
	//root is 1
	for(int i=0;i<to_road[1].size();i++){
		q.push(to_road[1][i]);
	}
	int cnt=1;
	bool book[MAX];memset(book,0,sizeof(book));book[1]=true;
	while(cnt<size && !q.empty()){
		int to=q.top().second;ll w=-q.top().first;q.pop();
		if(book[to]==false){
			//cout<<"to"<<to<<"w"<<w<<endl;
			book[to]=true;
			ans+=w;
			for(int i=0;i<to_road[to].size();i++){
				q.push(to_road[to][i]);
			}
			cnt++;
		}
	}
	//cout<<"ans:"<<ans<<endl;
	//printq();
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		road[u].push_back(make_pair(-w,v));
		road[v].push_back(make_pair(-w,u));
	}
	memset(newr,0,sizeof(newr));
	int cnt1,cnt2;//to have a date
	for(int i=0;i<k;i++){
		ll add;
		scanf("%lld",&add);
		if(!add) cnt1++;//a
		adds[i]=add;
		for(int j=1;j<=n;j++){
			int to;ll w;
			scanf("%lld",&w);
			if(!w) cnt2++;
			newr[i][j]=make_pair(-w,j);
		}
	}
	//bf
	if(k==0){
		copy_old_road();
		//print();
		ll re=solve(n);
		printf("%lld\n",re);
	}
	else if(k<=10){
		//int add_node=make_new_road(1);
		//ll re=solve(n+add_node);
		ll minre=1e17;
		for(int i=0;i<(1<<k);i++){
			cerr<<i<<endl;
			//int add_node=0;
			//cout<<i<<endl;
			pair<int,ll> add_node=make_new_road(i);
			ll re=solve(n+add_node.first);
			//cout<<"debug"<<minre<<" "<<re+add_node.second<<endl;
			minre=min(minre,re+add_node.second);
		}
		printf("%lld\n",minre);
	}
	//print();
	return 0;
}