#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+99;
int a[maxn];
ll nee[1099];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int num,sum=0;
	int ans=0,count=0;
	num=s.length();
//	clog<<num<<endl;
	for(int i=1;i<=num;i++){
	//	clog<<s[i-1]<<endl;
		if(s[i-1]>='0'&&s[i-1]<='9'){
			sum++;
			a[sum]=s[i-1]-48;
	//		cout<<a[sum]<<endl;
			count++;
		}
	}
//	cout<<count<<endl;
	if(count==1){
		for(int i=1;i<=num;i++){
			cout<<a[i];
			}
			return 0;
		}
	for(sum=1;sum<=count;sum++){
		for(int j=sum+1;j<=count;j++){
			if(a[j]>a[sum]){
				int temp=a[j];
				a[j]=a[sum];
				a[sum]=temp;
			}
	}
}
    for(int i=1;i<=count;i++){
	    cout<<a[i];
    }
/*	int dle=1;
	for(int i=1;i<=51;i++){
		nee[i]=dle;
		dle*=10;
//		cout<<nee[i]<<endl;
	}
	for(sum=1;sum<=count;sum++){
	    ans+=a[sum]*nee[count];
	    nee[count]/=10;
//	    cout<<sum<<endl;
//	    cout<<nee[count]<<endl;
//	    cout<<ans<<endl;
	}
	
//	cout<<ans;*/
	return 0;
}

