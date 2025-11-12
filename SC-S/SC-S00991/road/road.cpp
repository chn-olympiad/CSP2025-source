#include<bits/stdc++.h>
using namespace std;
struct ed{
	int u,v,w;
	ed *nex;
};
ed* a;
int b[15][10005],vis[100005],wz;
void add(int u,int v,int w){
	ed* t=new ed;
	ed* b=new ed;
	t->u=u;
	t->v=v;
	t->w=w;
	a->nex=b;
	while(1){
		if(b->nex==NULL)
		{b->nex=t;break;}
		else b=b->nex;
	}
	return;
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			cin>>b[i][j];
		}
	}
		ed* t=new ed;
		ed* t1=new ed;
		t=a->nex;
		t1=t->nex;
		int i=n;
		while(i--){
			if(t->v==t1->u)
			{
				ed* t2=new ed;
				t2->nex=t->nex;
				t->nex=t1;
				t2->nex->nex=t;
				t=t2;
				t1=t;
				a->nex=t;
			}
			if(t1->nex==NULL)break;
			t1=t1->nex;
		}
		while(1){
		if(vis[t->v]==0){
			wz+=t->w;
			vis[t->v]=1;
		}
		t=t->nex;
		if(t->nex==NULL)break;	
		}
	cout<<wz;
	return 0;
}