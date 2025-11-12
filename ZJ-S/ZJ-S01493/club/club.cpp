#include <bits/stdc++.h>
using namespace std;
int t,n,s1[3],ok[100010];
int a[100010][3],b[100010];
long long s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		s=s1[0]=s1[1]=s1[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				s1[0]++;ok[i]=0;
				b[i]=a[i][0]-max(a[i][1],a[i][2]);
				s+=a[i][0];
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				s1[1]++;ok[i]=1;
				b[i]=a[i][1]-max(a[i][0],a[i][2]);
				s+=a[i][1];
			}else{
				s1[2]++;ok[i]=2;
				b[i]=a[i][2]-max(a[i][1],a[i][0]);
				s+=a[i][2];
			}
		}
		for(int i=0;i<3;i++)
			if(s1[i]>n/2){
				int t=s1[i]-n/2;
				vector<int> p;
				for(int j=1;j<=n;j++)
					if(ok[j]==i) p.push_back(b[j]);
				sort(p.begin(),p.end());
				for(int j=0;j<t;j++)
					s-=p[j];
			}
		cout<<s<<"\n";
	}
 return 0;
}

