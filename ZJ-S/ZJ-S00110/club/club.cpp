#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a2[3];
int a[N][4];
vector<int> k;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++) a2[i]=0;
		k.clear();
		ans=0;
		cin>>n;
		//cout<<n<<endl;
		//cout<<a2[1]<<" "<<a2[2]<<" "<<a2[3]<<endl;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxa=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxa==a[i][1]) a2[1]++;
			else if(maxa==a[i][2]) a2[2]++;
			else if(maxa==a[i][3]) a2[3]++;
		}
		//cout<<a2[1]<<" "<<a2[2]<<" "<<a2[3]<<endl;
		int f,maxn=max(a2[1],max(a2[2],a2[3]));
		if(maxn==a2[1]) f=1;
		if(maxn==a2[2]) f=2;
		if(maxn==a2[3]) f=3;
		//cout<<f<<endl;
		//int c=0;
		for(int i=1;i<=n;i++){
			int maxa=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][f]==maxa){
				//c++;
				int m1,m2;
				if(f==1) m1=2,m2=3;
				if(f==2) m1=1,m2=3;
				if(f==3) m1=1,m2=2;
				int p=a[i][f]-max(a[i][m1],a[i][m2]);
				k.push_back(p);
			}
			ans+=maxa;
		}
		//cout<<c<<endl;
		/*cout<<ans<<endl;
		cout<<k.size()<<endl;
		sort(k.begin(),k.end());
		for(int i=0;i<k.size();i++){
			cout<<k[i]<<" ";
		}
		cout<<endl;
		cout<<k.size()<<endl;*/	
		int ma=maxn-n/2;
		//cout<<ma<<endl;
		for(int j=0;j<ma;j++){
			ans-=k[j];
			//cout<<k[j]<<" ";
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
