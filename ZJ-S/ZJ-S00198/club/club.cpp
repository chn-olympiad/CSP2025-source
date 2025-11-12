#include<bits/stdc++.h>
using namespace std;
long long T;
long long n;
long long a[100005][4];
long long b[100005];
long long c[4];
long long ans=0;
long long q[100005],w[100005],e[100005];
struct node{
	long long id,s;
};
node u[200005];
bool cmp(node x,node y){
	return x.s>y.s;
}
void dfs(int x){
	if(x>n){
		long long s=0;
		for(int i=1;i<=n;i++){
//			cout<<b[i]<<' ';
			s+=a[i][b[i]];
		}
//		cout<<endl;
//		cout<<ans<<endl;
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=3;i++){
		b[x]=i;
		if(c[i]<n/2){		
			c[i]++;	
			dfs(x+1);
			c[i]--;
		}
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		bool isA=1;
		bool isB=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q[i]=a[i][1];
			if(a[i][2]){
				isA=0;
			}
			if(a[i][3]){
				isA=0;
				isB=0;
			}
		}
		if(isA){
			sort(q+1,q+1+n);
			for(long long i=n;i>n/2;i--){
				ans+=q[i];
			}
			cout<<ans<<endl;
			continue;
		}
		else if(isB){
			int u[100005];
			long long ss=0;
			for(int i=1;i<=n;i++){
				u[i]=a[i][1]-a[i][2];
				ss+=a[i][2];
			}
			sort(u+1,u+1+n);
			for(int i=n;i>n/2;i--){
				ss+=u[i];
			}
			cout<<ss<<endl;
		}
		else if(n<=20){
			dfs(1);
			cout<<ans<<endl;
			continue;
		}
		else{
			
			bool b[100005];
			memset(b,0,sizeof(b));
			long long ss;
			long long s=0;
			for(int i=1;i<=n;i++){
				u[i].s=a[i][1]-a[i][2];
				u[i*2].s=a[i][3]-a[i][2];
				u[i].id=i;
				u[i*2].id=i;
				s+=a[i][2];
			}
			sort(u+1,u+1+2*n,cmp);
			int pp=0;
			for(int i=0;i<=n/2;i++){
				ss=s;
				pp=0;
				for(int j=1;pp<=n-i;j++){
					if(!b[u[j].id]){
						pp++;
						b[u[j].id]=1;
						ss+=u[j].s;
					}
				}
				for(int j=1;j<=n;j++){
					b[j]=0;
				}
				ans=max(ans,ss);
			}
			cout<<ans<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
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
