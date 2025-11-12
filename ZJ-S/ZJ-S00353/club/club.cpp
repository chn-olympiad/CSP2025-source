#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
long long a[MAXN][5];
int b[MAXN][5],srt[MAXN];
int c[MAXN][5];
int has[5];
bool cmp(int x,int y){
	//cout<<"Now cmp "<<x<<","<<y<<":"<<c[x][1]<<" "<<c[y][1]<<endl;
	if(c[x][1]==c[y][1]){
		if(c[x][2]==c[y][2]){
			return c[x][3]<=c[y][3];
		}
		else{
			return c[x][2]>=c[y][2];
		}
	}
	else{
		return c[x][1]>=c[y][1];
	}
	
}
void init(){
	int n,m;
	long long ans=0;
	scanf("%d",&n);
	m=n/2;
	has[1]=has[2]=has[3]=m;
	for(int i=1;i<=n;i++){
		srt[i]=i;
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		//int minn=min(a[i][1],min(a[i][2],a[i][3]));
		//a[i][1]-=minn;
		//a[i][2]-=minn;
		//a[i][3]-=minn;
		
		//ans+=minn;
		b[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
		
		//cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<" ";
		
		if(b[i][0]==a[i][1]){
			b[i][1]=1;
			if(a[i][2]>a[i][3]){
				b[i][2]=2;
				b[i][3]=3;
			}
			else{
				b[i][2]=3;
				b[i][3]=2;
			}
		}
		else if(b[i][0]==a[i][2]){
			b[i][1]=2;
			if(a[i][1]>a[i][3]){
				b[i][2]=1;
				b[i][3]=3;
			}
			else{
				b[i][2]=3;
				b[i][3]=1;
			}
		}
		else{
			b[i][1]=3;
			if(a[i][1]>a[i][2]){
				b[i][2]=1;
				b[i][3]=2;
			}
			else{
				b[i][2]=2;
				b[i][3]=1;
			}
		}
		c[i][1]=a[i][b[i][1]];
		c[i][2]=a[i][b[i][2]];
		c[i][3]=a[i][b[i][3]];
		//ans+=c[i][2];
		c[i][1]-=c[i][2];
		c[i][3]-=c[i][2];
		c[i][2]=0;
		//cout<<c[i][1]<<" "<<c[i][2]<<" "<<c[i][3]<<endl;
	}
	sort(srt+1,srt+n+1,cmp);
	
	/*
	int p,q;
	cin>>p>>q;
	cout<<cmp(p,q);
	cout<<endl<<ans<<endl;
	*/
	for(int i=1;i<=n;i++){
		int x=srt[i];
		//cout<<x<<":"<<b[x][1]<<" "<<b[x][2]<<" "<<b[x][3];//<<endl;
		//cout<<" "<<a[x][1]<<" "<<a[x][2]<<" "<<a[x][3]<<endl;
		if(has[b[x][1]]>0){
			ans+=a[x][b[x][1]];
			has[b[x][1]]--;
		}
		else if(has[b[x][2]]>0){
			ans+=a[x][b[x][2]];
			has[b[x][2]]--;
		}
		else if(has[b[x][3]]>0){
			ans+=a[x][b[x][3]];
			has[b[x][3]]--;
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t--){
		init();
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}