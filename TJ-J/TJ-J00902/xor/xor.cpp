#include<bits/stdc++.h>
using namespace std;
int n;
long long f;
long long a[500005];
bool v[500005];
int ans;
long long js(int st,int ed){
	long long cnt=a[st];
	for(int i=st;i<ed;i++){
		cnt^=a[i+1];
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			int j=i+k-1;
			bool b=0;
			for(int p=i;p<=j;p++){
				if(v[p]){
					i=p;
					b=1;
					break;
				}
			}
			if(b)continue;
			if(js(i,j)==f){
				ans++;
				for(int p=i;p<=j;p++){
					v[p]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
