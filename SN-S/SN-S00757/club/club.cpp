//陶家轩 SN-S00757 曲江第一学校 
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c;
	bool flag=false;
}stu[100005];
bool cmp(node x,node y){
	if(x.a!=y.a) return x.a>y.a;
	else if(x.b!=y.b) return x.b>y.b;
	else return x.c>=y.c;	
}
bool cmp1(node x,node y){
	if(x.a!=y.a) return x.a<y.a;
	else if(x.b!=y.b) return x.b<y.b;
	else return x.c<=y.c;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans1=0,ans2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			stu[i].flag=0;
		}
		int cnta=0;
		int cntb=0;
		int cntc=0;
		sort(stu+1,stu+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c&&cnta<n/2&&!stu[i].flag){
				ans1+=stu[i].a;	
				stu[i].flag=1;
				cnta++;
			}else if(stu[i].a<=stu[i].b&&stu[i].b>=stu[i].c&&cntb<n/2&&!stu[i].flag){
				ans1+=stu[i].b;
				stu[i].flag=1;
				cntb++;
			}else if(cntc<n/2){
				ans1+=stu[i].c;
				stu[i].flag=1;
				cntc++;
			}
		}
		for(int i=1;i<=n;i++){
			stu[i].flag=0;
		}
		cnta=0;
		cntb=0;
		cntc=0;
		sort(stu+1,stu+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(cnta<n/2&&!stu[i].flag){
				ans2+=stu[i].a;	
				stu[i].flag=1;
				cnta++;
			}else if(cntb<n/2&&!stu[i].flag){
				ans2+=stu[i].b;
				stu[i].flag=1;
				cntb++;
			}else if(cntc<n/2){
				ans2+=stu[i].c;
				stu[i].flag=1;
				cntc++;
			}
		}
		cout<<max(ans1,ans2)<<'\n';
		
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
