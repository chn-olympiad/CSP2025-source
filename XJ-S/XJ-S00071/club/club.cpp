#include<bits/stdc++.h>
using namespace std;
long long t,a[100010][10],mx[3],d[3][100010],n;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,sizeof(a),0);
		mx[1]=0,mx[2]=0,mx[3]=0;
		cin>>n;
		bool fa=true,fb=true;
		for(long i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			mx[1]+=a[1][i];
			mx[2]+=a[2][i];
			mx[3]+=a[3][i];
			d[1][i]=min(a[1][i]-a[2][i],a[1][i]-a[3][i]);
			d[2][i]=min(a[2][i]-a[1][i],a[2][i]-a[3][i]);
			d[3][i]=min(a[3][i]-a[2][i],a[3][i]-a[1][i]);
		}
	
		
		sort(d[1]+1,d[1]+n+1);
		sort(d[2]+1,d[2]+n+1);
		sort(d[3]+1,d[3]+n+1);
		for(long i=1;i<=n/2;i++){
			mx[1]-=d[1][i];
			mx[2]-=d[2][i];
			mx[3]-=d[3][i];
		}
		
		cout<<max(mx[1],max(mx[2],mx[3]))<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
