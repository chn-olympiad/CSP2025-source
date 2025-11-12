#include<bits/stdc++.h>
using namespace std;
struct node{
	int st,nd,rd,nd1,rd1,at;
};
node num[100001];
bool cmp(node p,node q){
	if(p.at<=q.at) return true;
	else if(p.nd1>=q.nd1) return true;
	else if(p.rd1>=q.rd1) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a=0,b=0,c=0,x,y,z,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				num[i].st=1;
				num[i].at=1;
				a++;
				ans+=x;
				if(y>=z){
					num[i].nd=2;
					num[i].nd1=x-y;
					num[i].rd=3;
					num[i].rd1=y-z;
				}
				else{
					num[i].nd=3;
					num[i].nd1=x-z;
					num[i].rd=2;
					num[i].rd1=z-y;
				}
			}
			else if(y>=x&&y>=z){
				num[i].st=2;
				num[i].at=2;
				b++;
				ans+=y;
				if(x>=z){
					num[i].nd=1;
					num[i].nd1=y-x;
					num[i].rd=3;
					num[i].rd1=x-z;
				}
				else{
					num[i].nd=3;
					num[i].nd1=y-z;
					num[i].rd=1;
					num[i].rd1=z-x;
				}
			}
			else{
				num[i].st=3;
				num[i].at=3;
				c++;
				ans+=z;
				if(x>=y){
					num[i].nd=1;
					num[i].nd1=z-x;
					num[i].rd=2;
					num[i].rd1=x-y;
				}
				else{
					num[i].nd=2;
					num[i].nd1=z-y;
					num[i].rd=1;
					num[i].rd1=y-x;
				}
			}
		}
		if(a<=(n/2)&&b<=(n/2)&&c<=(n/2)) printf("%d",ans);
		else{
			while(1){
				sort(num+1,num+n+1,cmp);
				if(a>n/2){
					for(int i=n/2+1;i<=a;i++){
						if(num[i].at==num[i].st){
							num[i].at=num[i].nd;
							ans-=num[i].nd1;
							if(num[i].nd==2){
								a--;
								b++;
							}
							else{
								a--;
								c++;
							}
						}
						if(num[i].at==num[i].nd){
							num[i].at=num[i].rd;
							ans-=num[i].rd1;
							if(num[i].rd==2){
								a--;
								b++;
							}
							else{
								a--;
								c++;
							}
						}
					}
				}
				if(b>n/2){
					for(int i=n/2+1+a;i<=a+b;i++){
						if(num[i].at==num[i].st){
							num[i].at=num[i].nd;
							ans-=num[i].nd1;
							if(num[i].nd==1){
								b--;
								a++;
							}
							else{
								b--;
								c++;
							}
						}
						if(num[i].at==num[i].nd){
							num[i].at=num[i].rd;
							ans-=num[i].rd1;
							if(num[i].rd==1){
								b--;
								a++;
							}
							else{
								b--;
								c++;
							}
						}
					}
				}
				if(c>n/2){
					for(int i=n/2+1+a+b;i<=a+b+c;i++){
						if(num[i].at==num[i].st){
							num[i].at=num[i].nd;
							ans-=num[i].nd1;
							if(num[i].nd==1){
								c--;
								a++;
							}
							else{
								c--;
								b++;
							}
						}
						if(num[i].at==num[i].nd){
							num[i].at=num[i].rd;
							ans-=num[i].rd1;
							if(num[i].rd==1){
								c--;
								a++;
							}
							else{
								c--;
								b++;
							}
						}
					}
				}
				if(a<=(n/2)&&b<=(n/2)&&c<=(n/2)) break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
