#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005],k,n,sum=0,aaa,bbb,aa=0,bb=0;
map<long long,long long> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		bbb=1;
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		aaa=b[i-1]^k;
//		cout<<b[i]<<" "<<aaa<<" "<<sum<<endl;
		if(a[i]==k){
			aa=i;
			sum++;
//			cout<<"sum++!"<<endl;
//			cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<aaa<<" "<<sum<<endl;
		
		}
		if(m[b[i]]!=0&&m[b[i]]>aa){
			sum++;
//			cout<<"sum++!"<<endl;
//			cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<aaa<<" "<<sum<<endl;
			aa=i;
			m[b[i]]=0;
		}else{
			m[b[i-1]^k]=i;
		}

	}
	cout<<sum;
	return 0;
}
/*
4 2
2 1 0 3
*/
//b[j]=k^b[i-1]
//3 5
//3^4^5
//
//10110
//00101
//10011
//a^b=c
//c^b=a
