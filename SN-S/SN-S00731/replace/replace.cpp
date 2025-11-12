#include<bits/stdc++.h>
using namespace std;
int n,q,jld;
string a[200010],b[200010],c[200010],d[200010];
int ans=0;
void is_not(string abc){
	bool jl=1;
	for(int i=0;i<abc.length();i++){
		if(d[jld][i]!=abc[i]){
			jl=0;
		}
	}
	if(jl){
		ans++;
		return;
	}
}
void find(string abc){
	string abc1=abc;
	for(int j=0;j<abc.length();j++){
		for(int i=1;i<=n;i++){
			bool f=1;
			for(int k=j;k<j+a[i].length();k++){
				if(abc1[k]!=a[i][k-j]){
					f=0;
				}
			}
			if(f){
				for(int k=j;k<j+a[i].length();k++){
					abc1[k]=b[i][k-j];
				}
				is_not(abc1);
			}
			abc1=abc;
		} 
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		jld=i;
		cin>>c[i]>>d[i];
		find(c[i]);
		printf("%d\n",ans);
		ans=0;
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
} 
