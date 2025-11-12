#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
typedef long long llint;
typedef unsigned long long ullint;

int T,n;

struct node{
	int max,dif,from;
}a[100002];
int tot1,tot2,tot3,maxtot,mtfrom;
llint ans;

bool cmp(const node& a,const node& b){
	
	return a.dif<b.dif;
}

int Set(int i,int t1,int t2,int t3){
	if(t1>t2){
		if(t1>t3){
			tot1+=1;
			a[i].max=t1;
			a[i].from=1;
			a[i].dif=t1-(t2>t3?t2:t3); 
		}else{
			tot3+=1;
			a[i].max=t3;
			a[i].from=3;
			a[i].dif=t3-(t1>t2?t1:t2);
		}
	}else{
		if(t2>t3){
			tot2+=1; 
			a[i].max=t2;
			a[i].from=2;
			a[i].dif=t2-(t1>t3?t1:t3); 
		}else{
			tot3+=1;
			a[i].max=t3;
			a[i].from=3;
			a[i].dif=t3-(t1>t2?t1:t2);
		}
	}
	ans+=a[i].max;
	//fprintf(stderr,"%d:%lld %d %d %d\n",i,ans,a[i].max,a[i].dif,a[i].from);
	return 0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>T;
	int t1,t2,t3;
	while(T>0){
		cin>>n;
		tot1=0;
		tot2=0;
		tot3=0;
		ans=0;
		for(int i=0;i<n;i+=1){
			cin>>t1>>t2>>t3;
			Set(i,t1,t2,t3);
		}
		if(tot1>tot2){
			if(tot1>tot3){
				maxtot=tot1;
				mtfrom=1;
			}else{
				maxtot=tot3;
				mtfrom=3;
			}
		}else{
			if(tot2>tot3){
				maxtot=tot2;
				mtfrom=2;
			}else{
				maxtot=tot3;
				mtfrom=3;
			}
		}
		maxtot-=(n>>1);
		//fprintf(stderr,"%d %d\n",maxtot,mtfrom);
		if(maxtot>0){
			t1=0;
			for(int i=0;i<n;i+=1){
				if(a[i].from==mtfrom){
					a[t1]=a[i];
					t1+=1;
				}
			}
			sort(a,a+t1,cmp);
			for(int i=0;i<maxtot;i+=1){
				ans-=a[i].dif;
			}
		}
		cout<<ans<<"\n";
		T-=1;
	}
	return 0;
}

