#include<bits/stdc++.h>
using namespace std; 
int t,n,ans=0,s[100005][5],num[5],f[100005][5],ad[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		for(int i=1;i<=n;i++){
			int cnt=max(s[i][1],s[i][2]);
			cnt=max(cnt,s[i][3]);
			ans+=cnt;
			for(int j=1;j<=3;j++){
				if(s[i][j]==cnt){
					num[j]++;
					f[++ad[j]][j]=i;
					break;
				}
			}
		}
		for(int i=1;i<=3;i++){
			while(num[i]>n/2){
				int g[100005],f1=0;
				for(int j=1;j<=ad[i];j++){
					if(i==3){
					g[++f1]=s[f[j][i]][i]-max(s[f[j][i]][1],s[f[j][i]][2]);	
					}
					else if(i==2){
					g[++f1]=s[f[j][i]][i]-max(s[f[j][i]][1],s[f[j][i]][3]);
					}
					else if(i==1){
					g[++f1]=s[f[j][i]][i]-max(s[f[j][i]][2],s[f[j][i]][3]);
					}
				}
				sort(g+1,g+1+f1);
				for(int j=1;j<=num[i]-(n/2);j++){
					ans-=g[j];
				}
				num[i]=0;
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<5;i++){
			num[i]=0,ad[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
