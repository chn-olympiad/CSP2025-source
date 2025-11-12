#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,p,t[4],o;
int a[100010][4],b[4];
int comp(int x,int y){
	for(int i=1;i<x;i++){
		if((a[i][y]-a[i][y+1])<(a[x][y]-a[x][y+1])){
			return i;
		}
	}
	return 0;
}
bool cmp(int x,int y){
	return x>y;
}
int tfind(int x){
	if(x==b[1]) return 1;
	if(x==b[2]) return 2;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans=0;
		p=0;
		o=0;
		scanf("%d",&k);
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for(int j=1;j<=k;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			b[1]=a[j][1];
			b[2]=a[j][2];
			b[3]=a[j][3];
			sort(a[j]+1,a[j]+4,cmp);
			p=comp(j,1);
			o=tfind(a[j][1]);
			if(t[o]*2<k){
				t[o]++;
				ans+=a[j][1];
			}
			if(p>0&&t[o]*2>=k){		
				ans=ans-a[p][1]+a[j][1]+a[p][2];
			//	cout<<a[p][1]<<" "<<a[p][2]<<" "<<a[j][1];
			}
			if(t[o]*2>=k&&p==0){
			 	o=tfind(a[j][2]);
				t[o]++;
				ans+=a[p][2];
			}
			//cout<<ans<<" ";
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
