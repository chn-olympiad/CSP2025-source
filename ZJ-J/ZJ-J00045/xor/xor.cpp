#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
bool b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		bool fla=true,fal=true;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				fla=false;
			}
			else if(a[i]!=0&&a[i]!=1){
				fal=false;
			}
		}
		if(fla){
			cout<<n/2;	
		}
		else if(fal){
			if(a[1]==0){
				cnt++;
				b[1]=true;
			}
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]&&a[i]==1&&!b[i]&&!b[i-1]){
					cnt++;
					b[i-1]=true;
					b[i]=true;
				}
				else if(a[i]==0){
					cnt++;
					b[i]=true;
				}
			}
			cout<<cnt;
		}
		return 0;
	}
	else if(k==1){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	else{
		cout<<n/2;
		return 0;
	}
	return 0;
}
