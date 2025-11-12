#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int T,ac,bc,cc,sum,lim;
struct people{
	int a,b,c;
}num[100009];
int cmp(people x,people y){
	return x.a > y.a;
}
int maxx(int a,int b,int c){
	return max(a,max(b,c));
}
int dfs(){
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		sum=0,lim=n/2;
		cin>>n;
		if(n<=200){
			for(int i=1;i<=n;i++){
				cin>>num[i].a>>num[i].b>>num[i].c; 
			}
//			dfs();
		}else{
			for(int i=1;i<=n;i++){
				cin>>num[i].a>>num[i].b>>num[i].c; 
			}
			for(int i=1;i<=n;i++){
				if(maxx(num[i].a,num[i].b,num[i].c)==num[i].a){
					ac++;
					sum+=num[i].a;
				}else if(maxx(num[i].a,num[i].b,num[i].c)==num[i].b){
					bc++;
					sum+=num[i].b;
				}
				else if(maxx(num[i].a,num[i].b,num[i].c)==num[i].c){
					cc++;
					sum+=num[i].c;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
