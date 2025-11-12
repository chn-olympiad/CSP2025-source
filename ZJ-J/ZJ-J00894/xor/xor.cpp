#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define IO
using namespace std;
#define ll long long
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
int n,k;int c0,c1;
int a[500005];
int b[500005];
struct node{
	int l,r;
}t[10005];
int p[10005];
int main(){
#ifdef IO
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//#else 
//	freopen("C:\\Users\\stu\\Desktop\\down\\xor\\xor3.in","r",stdin);
//	freopen("xor.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	scanf("%d %d",&n,&k);
	L(i,1,n){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		if(a[i]==1)c1++;
		if(a[i]==0)c0++;
	}
	if(c1==n){//10
		if(k==1){
			printf("%d",n);
		}else if(k==0){
			printf("%d",n/2);
		}else putchar('0');
		putchar('\n');
		return 0;
	}
	if(c0+c1==n){//20
		if(k==0){
			int ans=c0,old=-1;
			L(i,1,n){
				if(a[i]==0)continue;
				if(old==-1)old=a[i];
				else {
					if(a[i]==old){
						old=-1;
						ans++;
					}else old=a[i];
				}
			}
			printf("%d",ans);
		}else if(k==1){
			printf("%d",c1);
		}else putchar('0');
		putchar('\n');
		return 0;
	}
	if(k==0){
		int ans=c0,old=-1;
		L(i,1,n){
			if(a[i]==0)continue;
			if(old==-1)old=a[i];
			else {
				if(a[i]==old){
					old=-1;
					ans++;
				}else old=a[i];
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==1){
		int ans=c1;
		L(i,1,n){
			if(a[i]<2)continue;
			if(a[i]%2==0&&a[i+1]==a[i]+1){
				ans++;
				i++;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	int cnt=0,sz=1;
	L(i,0,n){
		L(j,i+1,n+1){
			if((b[j]^b[i])==k){
				t[cnt].l=i+1;
				t[++cnt].r=j;
			}
		}
	}
	sort(t+1,t+cnt+1,[](node a,node b){
		return a.l<b.l;
	});
	p[1]=t[1].r;
	L(i,2,cnt){
		if(p[sz]<t[i].l)p[++sz]=t[i].r;
		else p[lower_bound(p+1,p+sz+1,t[i].l)-p]=t[i].r;
	}
	printf("%d\n",sz);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
