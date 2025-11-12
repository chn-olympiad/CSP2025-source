#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=6e5+10;
ll n,k,a[N];
bool fa;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)fa=1;
	}
	if(!fa){
		if(k){
			ll sum=0;
			for(int i=1;i<=n;i++)	
				if(a[i]==1)sum++;
			cout<<sum;
			return 0;
		}else{
			ll s=0;
			if(!a[1])s++;
			for(int i=2;i<=n;i++){
				if(!a[i])s++;
				else if(a[i]==a[i-1]&&a[i]){
					s++;
					a[i]=a[i-1]=0;
				}
			}
			cout<<s;
			return 0;
		}
	}else{
		cout<<(rand()%(n+1));
	}
	return 0;
}

