#include<bits/stdc++.h>
using namespace std;
struct node{
	int b[4];
};
node a[100005];
long long n,T,m,sum,mx,mn,o,p,ans[4];
bool cmp1(node x,node y){
	return min(x.b[1]-x.b[2],x.b[1]-x.b[3])<min(y.b[1]-y.b[2],y.b[1]-y.b[3]);
}
void f1(){
	sort(a+1,a+n+1,cmp1);o=0;p=0;
	for(long long i=1;i<=m||min(a[i].b[1]-a[i].b[2],a[i].b[1]-a[i].b[3])<0;i++){
		if(a[i].b[1]-a[i].b[2]<a[i].b[1]-a[i].b[3]&&o<=m){
			o++;
			ans[1]-=a[i].b[1]-a[i].b[2];
		}else if(a[i].b[1]-a[i].b[3]<0){
			p++;
			ans[1]-=a[i].b[1]-a[i].b[3];
		}else{
			break;
		}
		
	}
}



bool cmp2(node x,node y){
	return min(x.b[2]-x.b[1],x.b[2]-x.b[3])<min(y.b[2]-y.b[1],y.b[2]-y.b[3]);
}
void f2(){
	sort(a+1,a+n+1,cmp2);o=0;p=0;
	for(long long i=1;i<=m||min(a[i].b[2]-a[i].b[3],a[i].b[2]-a[i].b[1])<0;i++){
		if(a[i].b[2]-a[i].b[1]<a[i].b[2]-a[i].b[3]&&o<=m){
			o++;
			ans[2]-=a[i].b[2]-a[i].b[1];
		}else if(a[i].b[2]-a[i].b[3]<0){
			p++;
			ans[2]-=a[i].b[2]-a[i].b[3];
		}else{
			break;
		}
		
	}
}



bool cmp3(node x,node y){
	return min(x.b[3]-x.b[2],x.b[3]-x.b[1])<min(y.b[3]-y.b[2],y.b[3]-y.b[1]);
}
void f3(){
	sort(a+1,a+n+1,cmp3);o=0;p=0;
	for(long long i=1;i<=m||min(a[i].b[3]-a[i].b[2],a[i].b[3]-a[i].b[1])<0;i++){
		if(a[i].b[3]-a[i].b[2]<a[i].b[3]-a[i].b[1]&&o<=m){
			o++;
			ans[3]-=a[i].b[3]-a[i].b[2];
		}else if(a[i].b[3]-a[i].b[1]<0){
			p++;
			ans[3]-=a[i].b[3]-a[i].b[1];
		}else{
			break;
		}
		
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		m=n/2;ans[1]=ans[2]=ans[3]=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
			ans[1]+=a[i].b[1];ans[2]+=a[i].b[2];ans[3]+=a[i].b[3];
		}
		f1();f2();f3();
		cout<<max(ans[1],max(ans[2],ans[3]))<<'\n';
	}
	return 0;
}
