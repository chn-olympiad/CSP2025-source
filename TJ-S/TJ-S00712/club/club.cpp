#include<bits/stdc++.h>
using namespace std;
int t;
struct stu1{
	int a,b,c;
}stu[100005];
long long int ans1;
long long int zuida=0;
//long long int q[205][205][205];
int ceng;
int biga,bigb,bigc;
int big;
int n;
void find(int ceng,int aa,int bb,int cc,long long int zhi){
	if(aa>(n/2)||bb>(n/2)||cc>(n/2)){
		return ;
	}
	if(ceng==n){
		zuida=max(zuida,zhi);
	}
	ceng++;
	find(ceng,aa+1,bb,cc,zhi+stu[ceng].a);
	find(ceng,aa,bb+1,cc,zhi+stu[ceng].b);
	find(ceng,aa,bb,cc+1,zhi+stu[ceng].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
//		memset(q,0,sizeof(q));
		biga=0;
		bigb=0;
		bigc=0;
		zuida=0;
		ans1=0;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			big=max(stu[i].a,max(stu[i].b,stu[i].c));
			ans1+=big;
			if(stu[i].a==big){
				biga++;
			}
			if(stu[i].b==big){
				bigb++;
			}
			if(stu[i].c==big){
				bigc++;
			}
		}
		if(biga<(n/2)&&bigb<(n/2)&&bigc<(n/2)){
			cout<<ans1<<endl;
			continue;
		}
		int duo=biga+bigb+bigc-n;
		if(n>30){
			if((biga-duo)<(n/2)&&(bigb-duo)<(n/2)&&(bigc-duo)<(n/2)){
				cout<<ans1<<endl;
				continue;
			}
		}
		find(0,0,0,0,0);
		cout<<zuida<<endl;	
	}

	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
