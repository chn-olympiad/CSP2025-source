#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,ans,c[50005],d[50005],e[50005];
void f(int i){
	if(i>a){
		return;
	}
	for(int i=1;i<=a;i++){
		if(!e[i]){
			e[i]=1;
		    d[i]+1;
            dfs[i];
			e[i+1]=1;
			e[i]=0;
			if(dfs(i)){
			     ans++;	
		    }
		    return;
		}
		for(int j=1;j>=a;j++){
			if(!e[j]){
				e[j]=1;
				d[i+1]=j;
			}
		}
	}
}

bool dfs(int i){
	if(i>a){
		return 1;
	}
	if(a[i]&&.passed<c[i]){
	    else{
			dfs(i).passed(i){
				return dfs(i*i.passed);
			}
			return dfs(i*i.passed);
	}
}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>a>>b>>s;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	f(i);
	d[i];
	cout<<ans;
	return 0;
}