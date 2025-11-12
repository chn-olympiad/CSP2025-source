#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,p[100005][5];
long long ans;
int in(){
	char c=getchar();
	int f=1,num=0;
	while(c>'9' && c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9' && c>='0'){
		num=(num<<3)+(num<<1)+(c-'0');
		c=getchar();
	}
	return num*f;
}
void solve(int a,int b,int c,int idx,long long sum,int n){
	if(idx==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(a+1<=n/2){
		solve(a+1,b,c,idx+1,sum+p[idx][1],n);
	}
	if(b+1<=n/2){
		solve(a,b+1,c,idx+1,sum+p[idx][2],n);
	}
	if(c+1<=n/2){
		solve(a,b,c+1,idx+1,sum+p[idx][3],n);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		int fl1=1,fl2=1,fl3=1;
		ans=0;
		int n;
		n=in();
		for(int i=1;i<=n;i++){
			p[i][1]=in();
			p[i][2]=in();
			p[i][3]=in();
			if(f[i][1]>0){
				fl1=0;
			}
			if(f[i][2]>0){
				fl2=0;
			}
			if(f[i][3]>0){
				fl3=0;
			}
		}
		solve(0,0,0,1,0,n);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
