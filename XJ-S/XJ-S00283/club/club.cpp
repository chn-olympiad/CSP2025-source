#include<iostream>
#include<algorithm>
#define MAXN 100005
using namespace std;

int t;
int n;
int zuidazhi=-1;
int ans=0;
int club1person=0;
int club2person=0;
int club3person=0;


struct myd{
	int m1;
	int m2;
	int m3;
	int form;
	int formci;
	bool used;
}; 
myd a[MAXN];

bool cmp1(myd x,myd y){
	return x.m1>y.m1;
} 
bool cmp2(myd x,myd y){
	return x.m2>y.m2;
}
bool cmp3(myd x,myd y){
	return x.m3>y.m3;
}

void fenlei(int x,int y,int z,int bh){
	zuidazhi=max(max(max(zuidazhi,x),y),z);
	if(zuidazhi==x){
		a[bh].form=1;
		int low=max(y,z);
		if(low==y) a[bh].formci=2;
		else if(low==z) a[bh].formci=3; 
	}
	else if(zuidazhi==y){
		a[bh].form=2;
		int low=max(x,z);
		if(low==x) a[bh].formci=1;
		else if(low==z) a[bh].formci=3;
	}
	else if(zuidazhi==z){
		a[bh].form=3;
		int low=max(x,y);
		if(low==x) a[bh].formci=1;
		else if(low==y) a[bh].formci=2;
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].m1>>a[j].m2>>a[j].m3;
			a[i].used=0;
			fenlei(a[j].m1,a[j].m2,a[j].m3,j);
		}
		sort(a+1,a+n+1,cmp1); 
		for(int j=1;j<=n;j++){
			if(club1person==n/2){
				break;
			}
			else if(a[i].form==1){
				ans+=a[j].m1;
				a[j].used=1;
				club1person++;
			}
		}
		sort(a+1,a+n+1,cmp2); 
		for(int j=1;j<=n;j++){
			if(club2person==n/2){
				break; 
			}
			else if(a[j].form==2||(a[j].used==0&&a[j].m2>a[j].m3)){
				ans+=a[j].m2;
				a[j].used=1;
				club2person++;
			}
		}
		sort(a+1,a+1+n,cmp3);
		for(int j=1;j<=n;j++){
			if(club3person==n/2){
				break;
			}
			else if(a[j].used==0){
				ans+=a[j].m3;
				club3person++;
			} 
		}
		cout<<ans<<endl;
		for(int j=1;j<=n;j++){
			a[j].used==0;
		}
		ans=0;
		club1person=0;
		club2person=0;
		club3person=0;
	}
	return 0;
}
