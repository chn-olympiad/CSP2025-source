#include<bits/stdc++.h>
using namespace std;
int t,n,c1,c2,c3,c[5],s;
struct V{
	int a[5],id[5];
}v[100005];
bool Z(V x,V y){
	return x.a[1]-x.a[2]>y.a[1]-y.a[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>v[i].a[j];
			}//1：a从大到小排   2：保留部门号
			if(v[i].a[1]==max({v[i].a[1],v[i].a[2],v[i].a[3]})){
				c1=v[i].a[1],v[i].id[1]=1;//下标：大小  数字：部门号
			}
			if(v[i].a[2]==max({v[i].a[1],v[i].a[2],v[i].a[3]})){
				c1=v[i].a[2],v[i].id[1]=2;
			}
			if(v[i].a[3]==max({v[i].a[1],v[i].a[2],v[i].a[3]})){
				c1=v[i].a[3],v[i].id[1]=3;
			}//最大
			if(v[i].a[1]==min({v[i].a[1],v[i].a[2],v[i].a[3]})){
				c3=v[i].a[1],v[i].id[3]=1;
			}
			if(v[i].a[2]==min({v[i].a[1],v[i].a[2],v[i].a[3]})){
				c3=v[i].a[2],v[i].id[3]=2;
			}
			if(v[i].a[3]==min({v[i].a[1],v[i].a[2],v[i].a[3]})){
				c3=v[i].a[3],v[i].id[3]=3;
			}//最小
			if(v[i].a[1]==v[i].a[1]+v[i].a[2]+v[i].a[3]-c1-c3){
				c2=v[i].a[1],v[i].id[2]=1;
			}
			if(v[i].a[2]==v[i].a[1]+v[i].a[2]+v[i].a[3]-c1-c3){
				c2=v[i].a[2],v[i].id[2]=2;
			}
			if(v[i].a[3]==v[i].a[1]+v[i].a[2]+v[i].a[3]-c1-c3){
				c2=v[i].a[3],v[i].id[2]=3;
			}//中间
			v[i].a[1]=c1,v[i].a[2]=c2,v[i].a[3]=c3;//a排序
		}
		sort(v+1,v+n+1,Z);//v按差值排序
		for(int i=1;i<=n;i++){
			if(c[v[i].id[1]]+1<=n/2){
				c[v[i].id[1]]++;
				s+=v[i].a[1];
			}else{//一个部门满员，另一个部门不可能满员
				c[v[i].id[2]]++;
				s+=v[i].a[2];
			}
		}
		cout<<s<<endl;
		s=c1=c2=c3=0;
		for(int i=1;i<=3;i++){
			c[i]=0;
		}//清零
	}
	return 0;
}