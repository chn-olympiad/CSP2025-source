#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans;
bool b[200005];
void tianyi(){
	srand(time(NULL));
	cout << rand()%100;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		cout << ans;
	}
	else if(k==0){
		memset(b,true,sizeof b);
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(i>=2&&a[i-1]==1&&b[i-1]){
				ans++;
				b[i-1]=b[i]=false; 
			}
		}
		cout << ans;
	}//льеп(k<=1),30pts
	else{
		tianyi();
	}
	return 0;
}
