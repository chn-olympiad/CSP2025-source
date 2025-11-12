#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100009],a2[100009],a3[100009],k[100009],g[4],f[100009];
long long ans=0;
void j(int s){
	for(int i=0;i<n;i++){
		f[i]=20002;
		if(k[i]==s){
			if(s==1){
				f[i]=max(a1[i]-a2[i],a1[i]-a3[i]);
			}
			else if(s==2){
				f[i]=max(a2[i]-a1[i],a2[i]-a3[i]);
			}
			else f[i]=max(a3[i]-a2[i],a3[i]-a1[i]);
		}
	}sort(f,f+n);
	for(int i=0;g[s]>n/2;g[s]--){
		ans-=f[i];
		i++;
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		g[1]=0;g[2]=0;g[3]=0;
		for(int i=0;i<n;i++)cin>>a1[i]>>a2[i]>>a3[i];
		for(int i=0;i<n;i++)k[i]=0;
		for(int i=0;i<n;i++){
			int y=(a1[i]>a2[i]&&a1[i]>a3[i])?1:(a2[i]>a3[i])?2:3;
			g[y]++;
			if(y==1){
				ans+=a1[i];
			}
			else if(y==2){
				ans+=a2[i];
			}
			else ans+=a3[i];
			k[i]=y;
		}
		if(g[1]>n/2)j(1);
		else if(g[2]>n/2)j(2);
		else if(g[3]>n/2)j(3);
		else cout<<ans<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
