#include<bits/stdc++.h>
using namespace std;
string s;
int k=1;
const int maxn=1e6+5;
int arr[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='a'&&s[i]<='z'){
			
		}else{
			arr[k]=s[i]-'0';
			k++;
		}
	}
	sort(arr+1,arr+k+1,cmp);
	for(int i=1;i<=k-1;i++){
		cout<<arr[i];
	}
	return 0;
} 
