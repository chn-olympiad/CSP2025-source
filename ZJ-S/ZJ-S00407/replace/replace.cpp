#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,ans;
string a[200005],b[200005],x,y;
vector<int>f(string x,string y){
	vector<int>ans;
	for(int i=0;i<x.size();i++){
		bool ok=1;
		for(int j=0;j<y.size();j++){
			if(i+j>=x.size()){
				ok=0;
				break;
			}
			if(x[i+j]!=y[j]){
				ok=0;
				break;
			}
		}
		if(ok){
			ans.push_back(i);
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(q==1&&n>100){
		printf("0\n");
		return 0;
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			string yuan=x;
			vector<int>ve=f(x,a[i]);
			for(int l=0;l<ve.size();l++){
				for(int j=0;j<b[i].size();j++){
					x[ve[l]+j]=b[i][j];
				}
				if(x==y){
					ans++;
				}
				x=yuan;
			}
			
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
