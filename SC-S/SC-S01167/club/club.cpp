#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
//struct bl{
//	int x,y,z;
//}t[N];
int n,a[5][N],nm;

int f1(int x){
	sort(a[x]+1,a[x]+n+1);
	int su=0;
	for(int i=n;i>(n>>1);i--)su+=a[x][i];
	return su;
}

int ff(int x,int s1,int s2,int s3){
	int a1=0,a2=0,a3=0;
	if(s1<nm)a1=(x<n?ff(x+1,s1+1,s2,s3):0)+a[1][x];
	if(s2<nm)a2=(x<n?ff(x+1,s1,s2+1,s3):0)+a[2][x];
	if(s3<nm)a3=(x<n?ff(x+1,s1,s2,s3+1):0)+a[3][x];
	return max(a1,max(a2,a3));
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
while(T--){
	cin>>n;
	nm=n>>1;
	bool l[4];l[1]=0;l[2]=0;l[3]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
		//t[i].x=0;
		//t[i].y=a[]
		if(a[1][i])l[1]=1;
		if(a[2][i])l[2]=1;
		if(a[3][i])l[3]=1;
	}
	//cout<<l[1]<<l[2]<<l[3]<<endl;
	if(l[1]+l[2]+l[3]==1){
		for(int i=1;i<4;i++){//cout<<i<<"  duifffyydfi"<<endl;
			if(l[i]){
				cout<<f1(i)<<endl;
				break;
			}
		}
		continue;
	}
	if(n<=10){
		cout<<ff(1,0,0,0)<<endl;
		continue;
	}
	int f[N];
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		f[i]=max(a[1][i],max(a[2][i],a[3][i]))+f[i-1];
	}
	cout<<f[n];
	
//	
//	for(int k=1;k<=nm);k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<4;j++){
//				for(int w=1)
//			}
//		}
//	}
//	
}
	return 0;
}
