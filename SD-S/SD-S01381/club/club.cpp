#include<iostream>
#include<algorithm>
using namespace std;

int t,ans,ma,n;
int tag[5];

struct node{
	int a,b,c,op;
}x[100005];

bool cmp1(const node &A,const node &B){
	int t1=A.a-max(A.b,A.c);
	int t2=B.a-max(B.b,B.c);
	return t1<t2;
}
bool cmp2(const node &A,const node &B){
	int t1=A.b-max(A.a,A.c);
	int t2=B.b-max(B.a,B.c);
	return t1<t2;
}
bool cmp3(const node &A,const node &B){
	int t1=A.c-max(A.b,A.a);
	int t2=B.c-max(B.b,B.a);
	return t1<t2;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		tag[1]=tag[2]=tag[3]=0;
		ans=0;
		ma=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].op=0;
		}
		for(int i=1;i<=n;i++){
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
				ma=x[i].a;
				tag[1]++;
				x[i].op=1;
			}
			if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
				ma=x[i].b;
				tag[2]++;
				x[i].op=2;
			}
			if(x[i].c>=x[i].a&&x[i].c>=x[i].b){
				ma=x[i].c;
				tag[3]++;
				x[i].op=3;
			}	
			ans+=ma;
		}	
		if(tag[1]>n/2){
			sort(x+1,x+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(x[i].op!=1)continue;
				if(tag[1]<=n/2)break;
				if(x[i].b>x[i].c){
					ans=ans-x[i].a;
					ans=ans+x[i].b;
					tag[1]--;
				}else{
					ans=ans-x[i].a;
					ans=ans+x[i].c;		
					tag[1]--;			
				}
			}
		}
		if(tag[2]>n/2){
			sort(x+1,x+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(x[i].op!=2)continue;
				if(tag[2]<=n/2)break;
				if(x[i].a>x[i].c){
					ans=ans-x[i].b;
					ans=ans+x[i].a;
					tag[2]--;
				}else{
					ans=ans-x[i].b;
					ans=ans+x[i].c;
					tag[2]--;					
				}
			}
		}
		if(tag[3]>n/2){
			sort(x+1,x+n+1,cmp3);
			for(int i=1;i<=n;i++){
				if(x[i].op!=3)continue;
				if(tag[3]<=n/2)break;
				if(x[i].a>x[i].b){
					ans=ans-x[i].c;
					ans=ans+x[i].a;
					tag[3]--;
				}else{
					ans=ans-x[i].c;
					ans=ans+x[i].b;
					tag[3]--;					
				}
			}
		}		
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
