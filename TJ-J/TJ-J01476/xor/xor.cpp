#include<bits/stdc++.h>
using namespace std;
int cnt[1048580],s[500005]
int main(){
	int n;
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		if(cnt[s[i]==0])cnt[s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(cnt[s[i]^k]){
			x[++m].l=i;
			x[m].r = cnt[(s[i]^k)];
		}
		
	}
	sort(x+1,x+m+1,cmp);
	if(m == 0){
		cout<<0<<endl;
	}
	int cnt=0.last =a[i].r;
	for(int i=2;i<=m;i++){
		if(a[i].l>last){
			cnt++;
			last = x
		}
	}
	//freopen("xor.in","r" .stdin); 
	//freopen("xor.out","w" .stdout); 
	
	return 0;
} 
