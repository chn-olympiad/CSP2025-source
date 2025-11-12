#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100005][4];
bool cmp1(int x,int y){return (a[x][1]-a[x][2])<=(a[y][1]-a[y][2]);}
bool cmp2(int x,int y){return (a[x][2]-a[x][3])<=(a[y][2]-a[y][3]);}
bool cmp3(int x,int y){return (a[x][3]-a[x][1])<=(a[y][3]-a[y][1]);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n,ans=0;
		cin>>n;
		vector<int> s1,s2,s3,a1(n),a2(n);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				s1.push_back(i);
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				s2.push_back(i);
			}else{
				s3.push_back(i);
			}
		}
		sort(begin(s1),end(s1),cmp1);
		int n1=s1.size();
		while(n1>(n/2)){
			int x=s1.back();
			s1.pop_back();n1--;
			s2.push_back(x);
		}
		sort(begin(s2),end(s2),cmp2);
		int n2=s2.size();
		while(n2>(n/2)){
			int x=s2.back();
			s2.pop_back();n2--;
			s3.push_back(x);
		}
		sort(begin(s3),end(s3),cmp3);
		int n3=s3.size();
		while(n3>(n/2)){
			int x=s3.back();
			s3.pop_back();n3--;
			s1.push_back(x);
		}
		for(auto i:s1) ans+=a[i][1];
		for(auto i:s2) ans+=a[i][2];
		for(auto i:s3) ans+=a[i][3];
		cout<<ans<<"\n";
	}
	return 0;
}