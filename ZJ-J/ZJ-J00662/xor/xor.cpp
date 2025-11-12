#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];
int n,k,c=0;

bool fun(int q,int p){
	int s=a[p];
	if(b[p]==true) return false;
	for(int i=p+1;i<=p+q-1;i++){
		s=s xor a[i];
		if(b[i]==true){
			return false;
		}
	}
	return s==k;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		for(int i=1;i<=n-q+1;i++){
			if(fun(q,i)){
				c++;
				for(int j=i;j<=i+q-1;j++){
					b[i]=true;
				}
			}		
		}
	}
	cout<<c;
	return 0;
}

