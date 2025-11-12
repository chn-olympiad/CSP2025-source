#include<bits/stdc++.h>
using namespace std;

int T,n,ans,limit,killer;

struct member{
	int sum[4];
	int fir,sec,thi;
	int d1;
	bool comm(int a,int b){
		return sum[a]>=sum[b];
	}
	int choose(){
		fir=1,sec=2;thi=3;
		if(!comm(sec,thi)) swap(sec,thi);
		if(!comm(fir,sec)) swap(fir,sec);
		if(!comm(sec,thi)) swap(sec,thi);
		d1=sum[fir]-sum[sec];
		return fir;
	}
}a[200050];
int forsort[100050];

struct b{
	int tag;
	int sum;
	int people;
}gov[4];
b temp;

void f(int a,int b){
	if(gov[a].sum<gov[b].sum){
		temp=gov[a];
		gov[a]=gov[b];
		gov[b]=temp;
	}
	return;
}

bool coffee(int x,int y){
	if(x<=y) return true;
	return false;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int maka=1; maka<=T; maka++){
		ans=0;
		for(int i=1; i<=3; i++){
			gov[i].sum=0,gov[i].tag=i,gov[i].people=0;
		}
		//Read
		scanf("%d",&n);
		limit=n/2;
		for(int i=1; i<=n; i++){
			scanf("%d%d%d",&a[i].sum[1],&a[i].sum[2],&a[i].sum[3]);
			gov[a[i].choose()].sum+=a[i].sum[a[i].fir] , gov[a[i].choose()].people++;
		}
		//Check
		bool flag=true;
		for(int goog=1; goog<=3; goog++){
			ans+=gov[goog].sum;
		}
		for(int i=1; i<=3; i++){
			if(gov[i].people>limit) flag=false;
		}
		if(flag){
			cout<<ans<<endl; 
		}else{
			//
			f(2,3);
			f(1,2);
			f(2,3);
			
			killer=gov[1].tag;
			int wahaha=1,i=1;
			while(wahaha!=gov[1].people+1){
				if(a[i].fir==killer){
					forsort[wahaha]=a[i].d1;
					wahaha++;
				}
				i++;
			}
			
			sort(forsort+1,forsort+gov[1].people+1,coffee);
			int length=gov[1].people-limit;
			
			for(int i=1; i<=length; i++){
				ans-=forsort[i];
			}
			cout<<ans<<endl; 
		}
	}
	return 0;
} 
