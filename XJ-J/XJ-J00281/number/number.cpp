#include<bits/stdc++.h>
using namespace std;
int main(){
	//#Shang4Shan3Ruo6Shui4
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long int a[100010],cnt=1,s,q=10,ct=0;
	cin>>s;
	for(long long int i=0;;i++){
		if(s/q!=0){
			q=q*10;
			cnt++;
		}
		else
			break;
	}
	q=10;
	long long int b=1;
	for(long long int i=0;i<cnt;i++){
		a[i]=s%q/b;
		q=q*10;
		b=b*10;
	}
	sort(a,a+cnt);
	for(long long int i=cnt-1;i>-1;i--)
		cout<<a[i];
	return 0;
} 

