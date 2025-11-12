#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>v(n*m);
    for(int i=0;i<n*m;i++){
    	cin>>v[i];
	}
	int ans=v[0];
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(v[i]==ans){
			ans=i+1;
	
			if(ans%n==0){
				if((ans/n) % 2==0)
					cout<<ans/n<<' '<<1;
				else cout<<ans/n<<' '<<n;
			}
			else {
				if((ans/n+1)% 2==0)
					cout<<ans/n+1<<' '<< n+1-ans%n;
				else cout<<ans/n+1<<' '<<ans%n;
			}
			break;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
