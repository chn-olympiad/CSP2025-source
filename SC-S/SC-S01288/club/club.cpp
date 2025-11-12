#include<bits/stdc++.h>
#define int long long
#define BAI ios_base::sync_with_stdio(0);
#define LAN cin.tie(0);
#define CSP cout.tie(0);
#define endl '\n'
using namespace std;
const int maxn=500101;
struct node {int k,w;};
int max1[maxn],max2[maxn],max3[maxn];
int T[4],ans=0;
int n,t,a[maxn][4]; 
vector<int> vk;  
void in(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j]; 
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	BAI LAN CSP 
	cin>>t;
	while(t--){
		memset(a,-1,sizeof(a)); ans=0; memset(T,0,sizeof(T)); vk.clear();
		in();
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
			int max0=0; 
			for(int j=1;j<=3;j++)if(a[i][j]>a[i][max0])max0=j;
			if(max0==1){l1++; max1[l1]=i; ans+=a[i][1];}
			if(max0==2){l2++; max2[l2]=i; ans+=a[i][2];}
			if(max0==3){l3++; max3[l3]=i; ans+=a[i][3];}
		}
		if(l1>n/2){
			for(int i=1;i<=l1;i++)vk.push_back(min(a[max1[i]][1]-a[max1[i]][2],a[max1[i]][1]-a[max1[i]][3]));
			sort(vk.begin(),vk.end());
			for(int i=0;i<vk.size()-n/2;i++)ans-=vk[i];
		}
		if(l2>n/2){
			for(int i=1;i<=l2;i++)vk.push_back(min(a[max2[i]][2]-a[max2[i]][1],a[max2[i]][2]-a[max2[i]][3]));
			sort(vk.begin(),vk.end());
			for(int i=0;i<vk.size()-n/2;i++)ans-=vk[i];
		}
		if(l3>n/2){
			for(int i=1;i<=l3;i++)vk.push_back(min(a[max3[i]][3]-a[max3[i]][2],a[max3[i]][3]-a[max3[i]][1]));
			sort(vk.begin(),vk.end());
			for(int i=0;i<vk.size()-n/2;i++)ans-=vk[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}


