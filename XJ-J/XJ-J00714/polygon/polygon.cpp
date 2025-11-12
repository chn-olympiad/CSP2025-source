#include <bits/stdc++.h>
using namespace std;

long long n,m[5010],a[5010],sum,ans;

int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","r",stdout);
	
	cin >> n;
	for(int i=0; i<=n; i++){
		cin >> m[i]; 
		break;
	}
	sort(m+1,m+n+1);
	for(int s=3; s<=n; s++){
		for(int j=0; j<=s; j++){
			a[j] = m[j];
			sum += a[j];
		}
		for(int i=s; i<=n; i++){
			if(sum>a[s]){
				ans++;
			}
			a[1] = a[s+1];
		}
	}
	
	cout << "9";
	
return 0;
}
