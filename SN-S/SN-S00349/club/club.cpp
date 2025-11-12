#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long an[100005],bn[100005],cn[100005];

struct ji{
	long long a,b,c;
}mem[100005];

long long ssum(long long x,long long na,long long nb,long long nc,long long n){

	long long sum=0,al=0,bl=0,cl=0,ao=mem[x].a,bo=mem[x].b,co=mem[x].c;
	if(x>n)return 0;
	if(ao<bo){
		bl=1;
		if(ao<co)cl=1;
		else al=1;
	}else{
		al=1;
		if(bo>co)bl=1;
		else cl=1;
	}	
	if(na<n/2&&al)
		sum=max(sum,ssum(x+1,na+1,nb,nc,n)+mem[x].a);
	if(nb<n/2&&bl)
		sum=max(sum,ssum(x+1,na,nb+1,nc,n)+mem[x].b);
	if(nc<n/2&&cl)
		sum=max(sum,ssum(x+1,na,nb,nc+1,n)+mem[x].c);
	return sum;
}

bool copa(long long x,long long y){
	
	long long xx=mem[x].a,yy=mem[y].a;
//	if(xx!=yy)
		return xx>yy;
//	else 
//		return (max(mem[x].b,mem[x].c))>(max(mem[y].b,mem[y].c));
}

bool copb(long long x,long long y){
	
	long long xx=mem[x].b,yy=mem[y].b;
//	if(xx!=yy)
		return xx>yy;
//	else 
//		return (max(mem[x].a,mem[x].c))>(max(mem[y].a,mem[y].c));
}

bool copc(long long x,long long y){
	
	long long xx=mem[x].c,yy=mem[y].c;
//	if(xx!=yy)
		return xx>yy;
//	else 
//		return (max(mem[x].b,mem[x].a))>(max(mem[y].b,mem[y].a));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=30){
			long long na=0,nb=0,nc=0,sum=0;
			for(long long i=1;i<=n;i++){
				long long ao,bo,co;
				cin>>ao>>bo>>co;
				mem[i].a=ao;
				mem[i].b=bo;
				mem[i].c=co;
			}
			
			cout<<ssum(0,0,0,0,n)<<'\n';			
		}
		else{
			long long na=0,nb=0,nc=0,sum=0;
			for(long long i=1;i<=n;i++){
				long long ao,bo,co;
				cin>>ao>>bo>>co;
				mem[i].a=ao;
				mem[i].b=bo;
				mem[i].c=co;
				if(ao>bo&&ao>co){
					an[++na]=i;
					continue;
				}
				if(bo>ao&&bo>co){
					bn[++nb]=i;
					continue;
				}
				if(co>bo&&co>ao){
					cn[++nc]=i;
				}
			}
			//取第一志愿
			sort(an+1,an+na+1,copa); 
			sort(bn+1,bn+nb+1,copb); 
			sort(cn+1,cn+nc+1,copc); 
			for(long long i=1;i<=na;i++){
				if(i<=n/2){
					if((mem[an[i]].a-mem[an[i+1]].a)<(max(mem[an[i]].b,mem[an[i]].c)-max(mem[an[i+1]].b,mem[an[i+1]].c))){
						swap(an[i],an[i+1]);
					}
					sum+=mem[an[i]].a;
					continue;
				}
				if(mem[an[i]].b<mem[an[i]].c)sum+=mem[an[i]].c;
				else sum+=mem[an[i]].b;
			}
			for(long long i=1;i<=nb;i++){
				if(i<=n/2){
					if((mem[bn[i]].b-mem[bn[i+1]].b)<(max(mem[bn[i]].a,mem[bn[i]].c)-max(mem[bn[i+1]].a,mem[bn[i+1]].c))){
						swap(bn[i],bn[i+1]);
					}
					sum+=mem[bn[i]].b;
					continue;
				}
				if(mem[bn[i]].a>mem[bn[i]].c)sum+=mem[bn[i]].a;
				else sum+=mem[bn[i]].c;
			}
			for(long long i=1;i<=nc;i++){
				if(i<=n/2){
					if((mem[cn[i]].c-mem[cn[i+1]].c)<(max(mem[cn[i]].a,mem[cn[i]].b)-max(mem[cn[i+1]].a,mem[cn[i+1]].b))){
						swap(cn[i],cn[i+1]);
					}
					sum+=mem[cn[i]].c;
					continue;
				}
				if(mem[cn[i]].a>mem[cn[i]].b)sum+=mem[cn[i]].a;
				else sum+=mem[cn[i]].b;
			}
			cout<<sum<<'\n';
		}
    }
	return 0;
}
