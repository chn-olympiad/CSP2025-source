#include<bits/stdc++.h>
using namespace std;
int vis[5];
int T,n,mxa=-1,sum;
struct iso{
	int a;
	int b;
	int c;
}tyx[10005];
bool cmp(iso a,iso b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tyx[i].a>>tyx[i].b>>tyx[i].c;
		}
		if(n==2){
			int a[100];
			a[1]=tyx[1].a+tyx[2].b;
			a[2]=tyx[1].a+tyx[2].c;
			a[3]=tyx[1].b+tyx[2].c;
			a[4]=tyx[1].b+tyx[2].a;
			a[5]=tyx[1].c+tyx[2].a;
			a[6]=tyx[1].c+tyx[2].b;
			for(int i=1;i<=6;i++) sum=max(sum,a[i]);
		}
		else{
			sort(tyx+1,tyx+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				cout<<tyx[i].a<<" ";
				sum+=tyx[i].a;
			}
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
} 
