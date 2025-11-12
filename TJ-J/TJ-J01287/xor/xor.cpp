#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int>o;


bool cmp(int x,int y){
	return x>y;
}
int a[500005];
int b[500005];
int cnt=0;
int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}	
	
	for(int i=2;i<=n;i++){
		a[i]=a[i]^a[i-1];
		if(a[i]==k){
			cnt++;
		}
	}
	cout<<cnt;
	//cout<<n;//#Shang4Shan3Ruo6Shui4
	return 0;
}
