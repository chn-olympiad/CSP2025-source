#include<bits/stdc++/h>
using namespace std;
struct qqq{
	int a,b,c;
};
//SN-S00672 贾羽鹤 陕西省西安中学  
struct qqs{
	int a,b;
};
struct cmp{
	bool operator()(qqq a,qqq b){
		return a.c<b.c;
	}
};
vector<qqs>a[10001];
priority_queue<qqq,vector<qqq>,cmp>qq;
queue<qqq>qw;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cout<<0;
//	int n,m,k;
//	cin>>n>>m>>k;
//	for(int i=0;i<m;i++){
//		int a1,a2,v;
//		cin>>a1>>a2>>v;
////		a[a1].push_back({a2,v});
////		a[a2].push_back({a1,v});
//		qq.push({a1,a2,v});
//	}
//	int bh=n;
//	for(int i=0;i<k;i++){
//		int v,v1;//v=0;
//		cin>>v;
//		n++;
//		for(int l=1;l<=n;l++){
//			cin>>v1;
//			qq.push({n,l,v1});
//		}
//	}
//	int ans=0;
//	
//	while(true){
//		if(qq.empty()){
//			break;
//		} 
//	}
//	while(true){
//		if(qq.empty())break;
//		qqq aa=qq.top();
//		qq.pop();
//		a[aa.a].push_back({aa.b,aa.c});
//		a[aa.c].push_back({aa.a,aa.c});
////		for(int i=0;i<a[aa.a].size();i++){
////			if(a[aa.a][i].a==)
////		}
//	}
//	bool b[100001]={0};
//	int dq=1;
//	while(1){
//		dq=qw.top().a;
//		for(int i=0;i<a[dq].size();i++){
//			qw.push({a[dq][i].a,vl+a[dq][i].b});
//		}
//		
//		
//		
//		if(b[]){
//			break;
//		}
//	}
fclose(stdout);
	fclose(stdin);
	return 0;
}
