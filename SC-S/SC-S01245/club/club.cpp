#include<bits/stdc++.h>

using namespace std;

int t,n,x[100099],y[100099],z[100099],cnt;

void dfs(int i,int p1,int p2,int p3,int h){
	
	if(p1>n/2||p2>n/2||p3>n/2)return ;
	
	if(i>n){
		
		cnt=max(cnt,h);
		return ;
		
	}
	
	i++;
	dfs(i,p1+1,p2,p3,h+x[i-1]);
	dfs(i,p1,p2+1,p3,h+y[i-1]);
	dfs(i,p1,p2,p3+1,h+z[i-1]);
	
	return ;
	
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		
		cin>>n;cnt=INT_MIN;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}

        if(n==100000){

            cnt=0;
			sort(x+1,x+1+n);
			for(int i=n;i>n/2;i--){
				cnt+=x[i];
			}
			cout<<cnt<<'\n';
			continue;
			
		}
        
		dfs(1,0,0,0,0);
		
		cout<<cnt<<'\n';
		
	}
	
	return 0;
	
}