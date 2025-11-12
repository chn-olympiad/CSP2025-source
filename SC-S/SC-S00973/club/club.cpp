#include <bits/stdc++.h>
using namespace std;
long long a[100010][5],b[5],c[100010],d[100010],e[100010];
int t,n;
long long sum=0,h=0;
void dfs(int s){
	if(s==n+1){
		sum=max(sum,h);
		return;
	}
	if(b[1]<n/2){
		b[1]++;
		h+=a[s][1];
		dfs(s+1);
		h-=a[s][1];
		b[1]--;
	}
	if(b[2]<n/2){
		b[2]++;
		h+=a[s][2];
		dfs(s+1);
		h-=a[s][2];
		b[2]--;
	}
	if(b[3]<n/2){
		b[3]++;
		h+=a[s][3];
		dfs(s+1);
		h-=a[s][3];
		b[3]--;
	}
}
int check1(){
	int v=0;
	for(int i=1;i<=n;i++)
		if(a[i][2]==0 && a[i][3]==0)
			v++;
	if(v==n) return 1;
	else return 0;
}
int check2(){
	int v=0;
	for(int i=1;i<=n;i++)
		if(a[i][3]==0)
			v++;
	if(v==n) return 1;
	else return 0;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		cin>>n;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=3;k++)
				cin>>a[j][k];
		for(int i=1;i<=3;i++) b[i]=0;
		if(n<=200) dfs(1);
		else if(check1()==1){
			for(int j=1;j<=n;j++) c[j]=a[j][1];
			sort(c+1,c+n+1,cmp);
			for(int j=1;j<=n/2;j++) sum+=a[j][1];
		}else if(check2()==1){
			for(int j=1;j<=n;j++){
				d[j]=a[j][1]-a[j][2];
				e[j]=d[j];
			}
			sort(e+1,e+n+1);
			int g=e[n/2],w1=1;
			for(int j=1;j<=n;j++){
				if(d[j]>=g){
					if(w1<=n/2) sum+=a[j][1];
					else sum+=a[j][2];
				}else sum+=a[j][2];
			}
		}else{
			for(int j=1;j<=n;j++)
				sum+=max(a[j][1],max(a[j][2],a[j][3]));
		}
		cout<<sum<<'\n';
	}
	return 0;
}