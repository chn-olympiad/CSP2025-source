#include<bits/stdc++.h>
using namespace std;
int per[505];
int arr[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		per[i]=i;
	}
	int ans=0;
	do{
		int nowang=0;
		int need=0;
		for(int i=1;i<=n;i++){
			if(arr[per[i]]<=nowang||s[i-1]=='0'){
				nowang++;
			}else{
				need++;
			}
		}
		if(need>=m){
			ans++;
		}
	}while(next_permutation(per+1,per+1+n));
	cout<<ans<<endl;
	return 0;
}
