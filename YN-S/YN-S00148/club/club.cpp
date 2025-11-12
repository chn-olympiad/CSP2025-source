#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1e5+100;

struct node{
	long long myd_1,myd_2,myd_3,max_id;
	long long abs1_2,abs2_3,abs1_3,min_abs;
//	friend bool operator <(const node a,const node b){
//		return a.min_abs>b.min_abs;
//	}
	void calc(){
		if (this->myd_1>=max(this->myd_2,this->myd_3)) this->max_id=1;
		else if (this->myd_2>=max(this->myd_1,this->myd_3)) this->max_id=2;
		else this->max_id=3;
		this->abs1_2=abs(this->myd_1-this->myd_2);
		this->abs2_3=abs(this->myd_2-this->myd_3);
		this->abs1_3=abs(this->myd_1-this->myd_3);
		return ;
	}
};

struct node_A{
	node ydata;
	friend bool operator <(const node_A a,const node_A b){
		return a.ydata.min_abs>b.ydata.min_abs;
	}
	void Acalc(){
		ydata.min_abs=min(ydata.abs1_2,ydata.abs1_3);
	}
};
struct node_B{
	node ydata;
	friend bool operator <(const node_B a,const node_B b){
		return a.ydata.min_abs>b.ydata.min_abs;
	} 
	void Bcalc(){
		ydata.min_abs=min(ydata.abs1_2,ydata.abs2_3);
	}
};
struct node_C{
	node ydata;
	friend bool operator <(const node_C a,const node_C b){
		return a.ydata.min_abs>b.ydata.min_abs;
	} 
	void Ccalc(){
		ydata.min_abs=min(ydata.abs2_3,ydata.abs1_3);
	}
};

long long t,n,ans;
node n_datas[MAXN];
node_A lsA_node;
node_B lsB_node;
node_C lsC_node;
priority_queue <node_A> pqA;
priority_queue <node_B> pqB;
priority_queue <node_C> pqC;

long long fread();

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
	t=fread();
	for (int Roundi=0;Roundi<t;Roundi++){
		ans=0;
//		scanf("%lld",&n);
		n=fread();
		for (int i=0;i<n;i++){
//			scanf("%lld %lld %lld",&n_datas[i].myd_1,&n_datas[i].myd_2,&n_datas[i].myd_3);
			n_datas[i].myd_1=fread();
			n_datas[i].myd_2=fread();
			n_datas[i].myd_3=fread();
			n_datas[i].calc();
			if (n_datas[i].max_id==1){
				lsA_node=node_A{n_datas[i]};
				lsA_node.Acalc();
				pqA.push(lsA_node);
			}else if(n_datas[i].max_id==2){
				lsB_node=node_B{n_datas[i]};
				lsB_node.Bcalc();
				pqB.push(lsB_node);
			}else{
				lsC_node=node_C{n_datas[i]};
				lsC_node.Ccalc();
				pqC.push(lsC_node);
			}
		}
		while (pqA.size()>n/2){
			if (pqA.top().ydata.myd_2>=pqA.top().ydata.myd_3){
				pqB.push(node_B{pqA.top().ydata});
			}else{
				pqC.push(node_C{pqA.top().ydata});
			}
			pqA.pop();
		}
		while (pqB.size()>n/2){
			if (pqB.top().ydata.myd_1>=pqB.top().ydata.myd_3){
				pqA.push(node_A{pqB.top().ydata});
			}else{
				pqC.push(node_C{pqB.top().ydata});
			}
			pqB.pop();
		}
		while (pqC.size()>n/2){
			if (pqC.top().ydata.myd_1>=pqC.top().ydata.myd_2){
				pqA.push(node_A{pqC.top().ydata});
			}else{
				pqB.push(node_B{pqC.top().ydata});
			}
			pqC.pop();
		}
		while (!pqA.empty()){
			ans+=pqA.top().ydata.myd_1;
			pqA.pop();
		}
		while (!pqB.empty()){
			ans+=pqB.top().ydata.myd_2;
			pqB.pop();
		}
		while (!pqC.empty()){
			ans+=pqC.top().ydata.myd_3;
			pqC.pop();
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

long long fread(){
	char c='#';
	long long res=0LL;
	do{
	    c=getchar();
	}while(c<'0'||c>'9');
	while (c>='0'&&c<='9'){
		res=res*10LL+c-'0';
		c=getchar();
	}
	return res;
}
