#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct tree{
	int to,ben,cost,nxt;
}t[2250010];
int coss[150010];
int hap[10010];
int cha[10010];
int sa[20];
int c[20];
long long ans,answers;
void jiann(int a,int b,int c,int number){
	t[number].cost=c;
	t[number].ben=a;
	t[number].to=b;
}
bool kk(tree a,tree b){
	return a.cost<=b.cost;
}
bool xun(){
	for(int i=1;i<=n;i++){
		if(cha[i]==0){
			return false;
		}
	}
	return true;
}
void gan(int yuu){
	memset(cha,0,sizeof(cha));
	sort(t+1,t+1+yuu,kk);
	bool kkk=true;
	int o=1;
	while(kkk){
		if(cha[t[o].ben]==0 || cha[t[o].to]==0 && t[o].ben!=t[o].to){
			ans+=t[o].cost;
			cha[t[o].ben]=1;
			cha[t[o].to]=1;
		}
		if(xun()){
			kkk=false;
		}
		o++;
	}
	answers=min(answers,ans);
}

void pin(int y){
	int biaoji=0;
	while(sa[biaoji]>0){
		for(int i=1;i<=n;i++){
			t[m+biaoji*n+i].ben=0;
			t[m+biaoji*n+i].to=i;
			t[m+biaoji*n+i].cost=coss[(sa[biaoji]-1)*n+i];
		}
		ans+=c[sa[biaoji]];
		biaoji++;
	}
	gan(m+y*n);
	ans=0;
}


void zheng(int i,int kk,int y){
	if(i==0){
		pin(y);
		return;
	}
	if(i+kk>n+1){
		return;
	}
	for(int j=kk;j<=k;j++){
		sa[y-i]=j;
		zheng(i-1,j+1,y);
		
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	answers=11529215046084697;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		jiann(a,b,c,i);
	}
	for(int i=1;i<=k;i++){
		bool kkkkkkkk=true;
		int a;
		cin>>a;
		c[i]=a;
		if(a!=0){
			kkkkkkkk=false;
		}
		for(int j=1;j<=n;j++){
			int p=i-1;
			cin>>coss[p*n+j];
			if(coss[p*n+j]!=0){
				kkkkkkkk=false;
			}
		}
		if(kkkkkkkk==true){
			cout<<0;
			return 0;
		}
	}
	ans=0;
	gan(m); 
	if(k==0){
		cout<<answers;
	}else{
		for(int i=1;i<=k;i++){
			ans=0;
			zheng(i,1,i);
		}
		cout<<answers;
	}
	fclose(stdin);
	fclose(stdout);
}
