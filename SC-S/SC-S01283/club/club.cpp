#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
	int myd;
	int num;
}a[MAXN],b[MAXN],c[MAXN];
int cmp(node x,node y){
	if(x.myd==y.myd) return x.num<y.num;
	else return x.myd>y.myd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,f=0;
		cin>>n;
		int x=n/2;
		int cab=0,cbb=0,ccb=0; 
		for(int j=1;j<=n;j++){
			cin>>a[j].myd>>b[j].myd>>c[j].myd;
			if(b[j].myd!=0||c[j].myd!=0) f=1;
			a[j].num=j;b[j].num=j;c[j].num=j;
		}
		int cnt=0;
		if(n==2){
			int maxx=0;
			cnt=a[1].myd+b[2].myd;
			if(cnt>maxx) maxx=cnt;
			cnt=a[1].myd+c[2].myd;
			if(cnt>maxx) maxx=cnt;
			cnt=b[1].myd+c[2].myd;
			if(cnt>maxx) maxx=cnt;
			cnt=b[1].myd+a[2].myd;
			if(cnt>maxx) maxx=cnt;
			cnt=c[1].myd+b[2].myd;
			if(cnt>maxx) maxx=cnt;
			cnt=c[1].myd+a[2].myd;
			if(cnt>maxx) maxx=cnt;
			cout<<maxx;
			continue;
		} 
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		if(f==0){
			int x=n/2; 
			for(int j=1;j<=x;j++){
				cnt+=a[j].myd;
			}
			cout<<cnt;
			continue;
		}
		if(n%3==0){
			int x=n/3;
			for(int j=1;j<=x;j++){
				if(a[j].num!=b[j].num&&a[j].num!=c[j].num&&b[j].num!=c[j].num) cnt+=a[j].myd+b[j].myd+c[j].myd;
				else cnt+=a[j+1].myd+b[j].myd+c[j].myd;
			}
		}
		else if(n%3==1){
			int k=n/3;
			if(a[k+1].myd==max(a[k+1].myd,max(b[k+1].myd,c[k+1].myd))) cnt+=a[k+1].myd;
			else if(b[k+1].myd==max(a[k+1].myd,max(b[k+1].myd,c[k+1].myd))) cnt+=b[k+1].myd;
			else cnt+=c[k+1].myd;
			for(int j=1;j<=k;j++){
				if(a[j].num!=b[j].num&&a[j].num!=c[j].num&&b[j].num!=c[j].num) cnt+=a[j].myd+b[j].myd+c[j].myd;
				else cnt+=a[j+1].myd+b[j].myd+c[j].myd;
			}
		}
		else{
			int k=n/3+1;
			if(a[k].myd==min(a[k].myd,min(b[k].myd,c[k].myd))) cnt-=a[k].myd;
			else if(b[k].myd==min(a[k].myd,min(b[k].myd,c[k].myd))) cnt-=b[k].myd;
			else cnt-=c[k].myd;
			for(int j=1;j<=k;j++){
				if(a[j].num!=b[j].num&&a[j].num!=c[j].num&&b[j].num!=c[j].num) cnt+=a[j].myd+b[j].myd+c[j].myd;
				else cnt+=a[j+1].myd+b[j].myd+c[j].myd;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 