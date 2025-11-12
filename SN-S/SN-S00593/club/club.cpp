#include<bits/stdc++.h>
using namespace std;
struct node{
	int q;
	int add;
	int z;
};
bool cmp(node a,node b){
	if(a.q<b.q) return a.q>b.q;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.ans","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;

		int d[n][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>d[i][j];
			}
		}
	
		vector<node> num(3*n);
		vector<int> flag(n,1);
		int p=0,a=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				num[a].q=d[i][j];
				num[a].add=p;
				num[a].z=j;
				a++;
			}
			p++;
		}

		sort(num.begin(),num.end(),cmp);
		int ans=0;
		int z1=0,z2=0,z3=0; 
		for(int i=0;i<3*n;i++){
			if(flag[ num[i].add ] != 1){
				continue;
			}else{
				if(num[i].z == 0 && z1 < n/2){
					z1++;
					flag[ num[i].add ]=2;
					ans=ans+num[i].q;
				}
				if(num[i].z == 1 && z2 < n/2){
					z2++;
					flag[ num[i].add ]=2;
					ans=ans+num[i].q;
				}
				if(num[i].z == 2 && z3 < n/2){
					z3++;
					flag[ num[i].add ]=2;
					ans=ans+num[i].q;
				}			
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
