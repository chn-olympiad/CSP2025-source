#include<bits/stdc++.h>
using namespace std;
string n;
long long a[10000000],b[10000000],q=0;
long long m=-100,ms,ans=1;
long long len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	len=n.size();
	for(long long i=0;i<len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[q]=n[i]-'0';
			q++;
		}
	}
	for(long long i=0;i<q;i++){
		m=-100;
		for(long long j=0;j<q;j++){
			if(a[j]>m&&a[j]!=-1){
				m=a[j];
				ms=j;
			}
		}
		b[ans]=m;
		a[ms]=-1;
		if(ans==q){
			for(long long l=1;l<=q;l++){
				cout<<b[l];
			}
			return 0;
		}
		ans++;
	}
}
