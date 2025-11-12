#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,maxn,club,cha,cha2;
}d[100005];
bool cmp(node a,node b){
	if(a.cha>b.cha) return 1;
	else if(a.cha==b.cha){
		if(a.cha2>b.cha2) return 1;
		else if(a.cha2==b.cha2){
			if(a.maxn>b.maxn){
				return 0;
			}
		}
		else return 0;
	}
	return 0;
}
int t,n;
int x[5];
long long num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		num=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].a>d[i].b&&d[i].a>d[i].c){
				d[i].maxn=d[i].a;
				d[i].club=1;
				if(d[i].b>d[i].c){
					d[i].cha=d[i].a-d[i].b;
					d[i].cha2=d[i].b-d[i].c;
				}
				else{
					d[i].cha=d[i].a-d[i].c;
					d[i].cha2=d[i].c-d[i].b;
				}
			}
			else if(d[i].b>d[i].a&&d[i].b>d[i].c){
				d[i].maxn=d[i].b;
				d[i].club=2;
				if(d[i].a>d[i].c){
					d[i].cha=d[i].b-d[i].a;
					d[i].cha2=d[i].a-d[i].c;
				}
				else{
					d[i].cha=d[i].b-d[i].c;
					d[i].cha2=d[i].c-d[i].a;
				}
			}
			else{
				d[i].maxn=d[i].c;
				d[i].club=3;
				if(d[i].a>d[i].b){
					d[i].cha=d[i].c-d[i].a;
					d[i].cha2=d[i].a-d[i].b;
				}
				else{
					d[i].cha=d[i].c-d[i].b;
					d[i].cha2=d[i].b-d[i].a;
				}
			}
//			cout<<d[i].maxn<<" "<<d[i].club<<endl;
		}
		x[1]=x[2]=x[3]=n/2;
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++){
			int p=d[i].club;
			if(x[p]>=1){
				num+=d[i].maxn;
				x[p]-=1;
			}
			else{
				if(p==1){
					if(d[i].b>d[i].c&&x[2]>=1){
						num+=d[i].b;
						x[2]-=1;
					}
					else{
						num+=d[i].c;
						x[3]-=1;
					}
				}
				else if(p==2){
					if(d[i].a>d[i].c&&x[2]>=1){
						num+=d[i].a;
						x[1]-=1;
					}
					else{
						num+=d[i].c;
						x[3]-=1;
					}
				}
				else{
					if(d[i].b>d[i].a&&x[2]>=1){
						num+=d[i].b;
						x[2]-=1;
					}
					else{
						num+=d[i].a;
						x[1]-=1;
					}
				}		
			}
//			cout<<num<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
		}
		cout<<num<<endl;
	}
	return 0;
}
