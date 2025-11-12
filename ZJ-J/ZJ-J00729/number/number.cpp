#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000050];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long ans=0,s=0,p=0;
	cin>>a;
	for(long long s=0;s<a.size();s++){
		if(a[s]=='1' || a[s]=='2'|| a[s]=='3'|| a[s]=='4'|| a[s]=='5'|| a[s]=='6'|| a[s]=='7'|| a[s]=='8'|| a[s]=='9'|| a[s]=='0'){
			if(a[s]=='0'){
				p++;
//				ans++;
				continue;
			}
			b[ans]=a[s]-'0';
			ans++;
		}
	}
	sort(b,b+ans);
	for(long long i=ans-1;i>=0;i--){
		cout<<b[i];
	}
	for(long long i=0;i<p;i++){
		cout<<"0";
	}
	return 0;
}
