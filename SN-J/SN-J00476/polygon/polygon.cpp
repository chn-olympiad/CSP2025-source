#include<bits/stdc++.h>
using namespace std;
int n,p[5001],ans=0,u,s;
vector<int> f;
vector<int> v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	v.push_back(0);
	f.push_back(0);
	memset(p,0,sizeof(p));
	for(int i=0;i<n;i++){
		cin>>u;
		p[u]++;
	}
	for(int i=0;i<1000;i++){
		if(p[i]){
			for(int k=0;k<p[i];k++){
				s=v.size();
				for(int j=0;j<s;j++){
					v.push_back(v[j]+i);
					f.push_back(f[j]+1);
//					for(int w=0;w<v.size();w++){
//						cout<<v[w]<<","<<f[w]<<" - ";
//					}
//					cout<<endl;
					if(((f[j]+1)>=3) && ((v[j]+i)>i*2)){
//						cout<<"S"<<v[j]+i<<endl;
						ans++;
						if(ans==998244353){
							ans=0;
						}
					}
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
