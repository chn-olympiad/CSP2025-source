#include<bits/stdc++.h>
using namespace std;
long long t,n,x,num[5],sum=0;
struct node{
	long long a,b,x,c;
};node g[100005];
bool cmp(node x,node y){
	return x.c<y.c; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(g,0,sizeof(g));
		sum=0;
		memset(num,0,sizeof(num));
		cin>>n;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				cin>>x;
				if(x>g[k].a){
					g[k].b=g[k].a;
					g[k].a=x;
					g[k].x=j;
				}else{
					if(x>g[k].b){
						g[k].b=x;
					}
				}
			}
			g[k].c=g[k].a-g[k].b;
		//	cout<<g[k].c<<" "<<g[k].x<<endl;
			num[g[k].x]++;
			sum+=g[k].a;
		}
	//	cout<<sum<<endl;
		sort(g+1,g+1+n,cmp);
		for(int j=1;j<=3;j++){
			if(num[j]>n/2){
				long long cnt=0;
				for(int k=1;k<=n&&cnt<num[j]-n/2;k++){
					if(g[k].x==j){
						sum-=g[k].c;
						cnt++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
