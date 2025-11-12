#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
const int M=1e3+10;
//priority_queue greater
int n;
struct Node{
	int A,B,C;
	int cab,cbc,cac;
}e[N];
int ans=0;
void dfs(int k,int cnta,int cntb,int cntc,int num){
	if(k==n+1){
		ans=max(ans,num);
		return ;
	}
	if(cnta<n/2){
		dfs(k+1,cnta+1,cntb,cntc,num+e[k].A);
	} 
	if(cntb<n/2){
		dfs(k+1,cnta,cntb+1,cntc,num+e[k].B);
	}
	if(cntc<n/2){
		dfs(k+1,cnta,cntb,cntc+1,num+e[k].C);
	}
}
bool cmp1(Node A,Node B){
	return A.A>B.A;
}
int a[N],b[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		ans=0;
		bool check1=true;
		bool check2=true;
		for(int i=1;i<=n;i++){
			cin>>e[i].A>>e[i].B>>e[i].C;
			if(e[i].B!=0||e[i].C!=0) check1=false;
			if(e[i].C!=0) check2=false;
			e[i].cab=e[i].A-e[i].B;
			e[i].cbc=e[i].B-e[i].C;
			e[i].cac=e[i].A-e[i].C;
		}
		if(check1){
			sort(e+1,e+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=e[i].A;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(check2){
			int cnta=0,cntb=0;
			for(int i=1;i<=n;i++){
				if(e[i].A>e[i].B){
					if(cnta<n/2){
						a[++cnta]=i;
						ans+=e[i].A;
					}else if(cntb<n/2){
						b[++cntb]=i;
						ans+=e[i].B;
					}else{
						int maxA=-1;
						int maxAi=-1;
						for(int j=1;j<=cnta;j++){
							if(maxA<e[a[j]].A-e[i].A){
						 		maxA=e[a[j]].A-e[i].A;
						 		maxAi=a[j];
							}
						}
						int maxB=-1;
						int maxBi=-1;
						for(int j=1;j<=cntb;j++){
							if(maxB<e[b[j]].B-e[i].B){
								maxB=e[b[j]].B-e[i].B;
								maxBi=b[j];
							}
						}
						if(maxA==-1&&maxB==-1){
							continue;//·ÅÔÚc 
						}
						if(maxA>maxB){
							ans+=maxA;
							a[maxAi]=i;
						}else{
							ans+=maxB;
							b[maxBi]=i;
						}
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
