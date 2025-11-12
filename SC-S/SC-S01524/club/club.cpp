#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int x,y,z;
long long p,aa=-1;
int n,a[100005],b[100005],c[100005];
void dfs(int s){
	if(s==n+1){
		aa=max(aa,p);
		return ;
	}
	if(x!=0){
		p+=a[s];
		x--;
		s++;
		dfs(s);
		s--;
		x++;
		p-=a[s];
	}
	if(y!=0){
		p+=b[s];
		y--;
		s++;
		dfs(s);
		s--;
		y++;
		p-=b[s];
	}
	if(z!=0){
		p+=c[s];
		z--;
		s++;
		dfs(s);
		s--;
		z++;
		p-=c[s];
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		aa=-1;
		int q=0,w=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0){
				q=1;
			}
			if(b[i]!=0){
				w=1;
			}
		}
		
		x=n/2;
		y=x;
		z=x;
		dfs(1);
		if(w==0&&q==0){
			int s=n/2;
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=s;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
			break;
		}
		cout<<aa<<'\n';
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
