#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n,a1[N],a2[N],a3[N],ans=0;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int p=1;p<=t;p++){
		
		cin >> n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		
		if(n==2){
			ans=max(max(max(a1[1]+a2[2],a1[1]+a3[2]),max(a2[1]+a1[2],a2[1]+a3[2])),max(a3[1]+a1[2],a3[1]+a2[2]));
		}
		else{
			sort(a1+1,a1+n+1);
			sort(a2+1,a2+n+1);
			sort(a3+1,a3+n+1);
			if(n==4) ans=a1[n]+a2[n]+a3[n]+max(max(a1[n-1],a2[n-1]),a3[n-1]);
			if(n==10) ans=a1[n]+a2[n]+a3[n]+a1[n-1]+a2[n-1]+a3[n-1]+a1[n-2]+a2[n-2]+a3[n-2]+max(max(a1[n-3],a2[n-3]),a3[n-3]);
		}
		
		
		
		cout << ans << endl;
	}
	
	
	return 0;
}
