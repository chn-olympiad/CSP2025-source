# include<bits/stdc++.h>
using namespace std;
long long n,a[10000],cnt,b=1;
bool f=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(f==true){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++){
				b*=(n+1-j);
				if(b>=998224353){
					b%=998224353;
				}
				b/=j;
			}
			cnt+=b;
			b=1;
			if(cnt>=998224353){
				cnt%=998224353;
			}
		}
	}
	cout<<cnt;
	return 0;
}
