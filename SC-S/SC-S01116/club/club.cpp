#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010][5],f[210][210];
int cho[40],qz[5];
int read(){
	int x=0,p=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*p;
}
int tot;
void dfs(int s,int n){
	if(s>n){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][cho[i]];
		}
		tot=max(tot,ans);
		//cout<<ans<<' '<<cho[1]<<' '<<cho[2]<<'\n';
		return;
	}
	for(int i=1;i<=3;i++){
	//	cout<<s<<' '<<i<<'\n';
		cho[s]=i;
		qz[i]++;
		if(qz[i]>n/2){
			qz[i]--;
			//cout<<i<<'\n';
			continue;
		}
		dfs(s+1,n);
		qz[i]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		int n=read();
		bool ch2=1,ch3=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(j==2 and a[i][j]!=0){
					ch2=0;
				}
				if(j==3 and a[i][j]!=0){
					ch3=0;
				}
			}
		}
		if(n<=10){
			dfs(1,n);
			memset(qz,0,sizeof qz);
			cout<<tot<<'\n';
			tot=0;
		}
		else if(ch2){
			vector<int> vec;
			for(int i=1;i<=n;i++){
				vec.push_back(a[i][1]);
			}
			sort(vec.begin(),vec.end(),greater<int>());
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=vec[i-1];
			}
			cout<<ans<<'\n';
		}else if(ch3){
			int ans=0;
			int l=0,r=0;
			vector<pair<int,bool>> c;
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],a[i][2]);
				if(a[i][1]>a[i][2])l++;
				else r++;
				c.push_back({abs(a[i][1]-a[i][2]),(a[i][1]>a[i][2])});
			}
			sort(c.begin(),c.end());
			int h=abs(r-l)/2;
			if(l>r){
				for(pair<int,bool> i:c){
					if(h==0)break;
					if(i.second){
						h--;
						ans-=i.first;
					}
				}
			}else{
				for(pair<int,bool> i:c){
					if(h==0)break;
					if(!i.second){
						h--;
						ans-=i.first;
					}
				}
			}
			cout<<ans<<'\n';
		}else if(n<=200){
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++){
				for(int j=min(n/2,i);j>=0;j--){
					for(int k=min(n/2,i);k>=0;k--){
						if(j+k<=i){
							if(j+k<i and i-(j+k)<=n/2)f[j][k]=max(f[j][k],f[j][k]+a[i][3]);
							if(j>0 and j<=n/2)f[j][k]=max(f[j][k],f[j-1][k]+a[i][1]);
							if(k>0 and k<=n/2)f[j][k]=max(f[j][k],f[j][k-1]+a[i][2]);
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					ans=max(ans,f[i][j]);
					//	cout<<f[i][j]<<' ';
				}
				//	cout<<'\n';
			}
			cout<<ans<<'\n';
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}