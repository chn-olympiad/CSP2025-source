#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],s[100100],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int num=s[1];
	sort(s+1,s+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(s[i]==num) {
			k=i;
		}
	}
	int yu=k%n,shang=k/n;
	if(yu==0){
		if(shang%2==0) cout<<1<<' '<<shang;
		else cout<<n<<' '<<shang;
		cout<<shang<<' '<<n;
		return 0;
	}
	if(shang%2==1) cout<<yu+1<<' '<<n-yu+1;
	else cout<<shang+1<<' '<<yu;
	return 0;
} 
