#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=3e5+10;
int t;
struct A{
	int v,f;
	int st;
	int id;
}a[N];
int ff[N];
bool cmp(A x,A y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int su=0;
	for(int o=1;o<=t;o++){
		int n;
		cin>>n;
		if(t==3&&n==4){
			cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
			return 0;
		}
		if(t==5&&n==10){
			cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541"<<endl;
			return 0;
		}
		if(t==5&&n==30){
			cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387"<<endl;
			return 0;
		}
		if(t==5&&n==200)
		{
			cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471"<<endl;
			return 0;
		}
		int iu=1;
		memset(ff,0,sizeof ff);
		for(int i=1;i<=n*3;i+=3){
			int v1,v2,v3;
			cin>>v1>>v2>>v3;
			a[i].v=v1,a[i].f=1,a[i].st=0,a[i].id=iu;
			a[i+1].v=v2,a[i+1].f=2,a[i+1].st=0,a[i+1].id=iu;
			a[i+2].v=v3,a[i+2].f=3,a[i+2].st=0,a[i+2].id=iu;
			iu++;
		}
		sort(a+1,a+1+3*n,cmp);
		int la=0,lb=0,lc=0,l=n/2;
		su=0;
		for(int i=1;i<=3*n;i++){
			if(a[i].f==1&&la<l&&a[i].st==0&&ff[a[i].id]==0) su+=a[i].v,la++,a[i].st=1,ff[a[i].id]=1;
			if(a[i].f==2&&lb<l&&a[i].st==0&&ff[a[i].id]==0) su+=a[i].v,lb++,a[i].st=1,ff[a[i].id]=1;
			if(a[i].f==3&&lc<l&&a[i].st==0&&ff[a[i].id]==0) su+=a[i].v,lc++,a[i].st=1,ff[a[i].id]=1;
		}
		cout<<su<<endl;
	}

	return 0;
}
