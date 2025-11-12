#include<bits/stdc++.h>
using namespace std;
int n;
int b[5][100005];
long long ans=0;
int a[100005][5];
inline void print(){
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=b[i][0];j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
}
inline void slove(){
/*
b[部门][数量] 
*/
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		int mx=-1,pos=0;
		for(int j=1;j<=3;j++){
			if(mx<a[i][j]) pos=j,mx=a[i][j];
		}
		b[pos][++b[pos][0]]=i;
		ans+=(long long)mx;
	}
	//print();
	for(int i=1;i<=3;i++){
		while(b[i][0]>n/2){
			int pos1=0,p1=INT_MAX,pos2=0,p2=INT_MAX;
			for(int j=1;j<=b[i][0];j++){
				if(b[(i+1)%3][0]<=n/2&&p1>a[b[i][j]][i]-a[b[i][j]][(i+1)%3]){
					pos1=j;
					p1=a[b[i][j]][i]-a[b[i][j]][(i+1)%3];
				}
				if(b[(i+2)%3][0]<=n/2&&p2>a[b[i][j]][i]-a[b[i][j]][(i+2)%3]){
					pos2=j;
					p2=a[b[i][j]][i]-a[b[i][j]][(i+2)%3];
				}
			}
			if(p1<p2){
				b[(i+1)%3][++b[(i+1)%3][0]]=b[i][pos1];
				b[i][pos1]=b[i][b[i][0]--];
				ans-=(long long)p1;
				//cout<<i<<" "<<p1<<" "<<pos1<<endl;
			}else{
				b[(i+2)%3][++b[(i+2)%3][0]]=b[i][pos2];
				b[i][pos2]=b[i][b[i][0]--];
				ans-=(long long)p2;
			//	cout<<i<<" "<<p2<<" "<<pos2<<endl;
			}
		//	cout<<endl;
		//	print();
		//	cout<<endl;
		}
	}
	
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		slove();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
