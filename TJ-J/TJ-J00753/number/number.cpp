#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
long long n,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lena=s.length();
	for(int i=0;i<lena;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
			
		}
	}
	sort(a,a+sum);
	for(int i=0;i<sum;i++){
		cout<<a[sum-i-1];
	}
//for(int i=0;i<sum;i++){
//	cout<<a[i]<<' ';
//}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
//#Shang4Shan3Ruo6Shui4
