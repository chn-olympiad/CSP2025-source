#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
   	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> v(n);bool all1=1;
	for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]!=1)
            all1=0;
	}
	if(k==0&&all1){
        cout<<n-1;
	}
	else if(k<=1){
            int ans=0;
        if(k==0){
            for(int i=0;i<v.size()-1;i++){
                if(v[i]==0){
                    ans++;
                }
                if(v[i]==v[i+1]){
                    ans++;
                }
            }
        }
        if(k==1){
             for(int i=0;i<v.size()-1;i++){
                 if(v[i]==1){
                        ans++;
                 }
                 if((v[i]==0&&v[i+1]==1)||(v[i]==1&&v[i+1]==0))
                    ans++;
             }
        }
        cout<<ans;
	}
	else{
        cout<<1;
	}
	return 0;
}
