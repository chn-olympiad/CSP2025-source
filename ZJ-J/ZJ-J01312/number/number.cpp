#include <bits/stdc++.h>
using namespace std;
string s;
int arr[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[cnt++]=s[i]-48;
		}
	}
	sort(arr,arr+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
