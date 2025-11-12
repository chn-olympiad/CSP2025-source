#include<bits/stdc++.h>
using namespace std;
int arr[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=1;
	string s;
	cin>>s;
	int z=s.size();
	for(int i=0;i<z;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[k]=s[i]-'0';
			k++;
		}
	}
	sort(arr+1,arr+k,cmp);
	for(int i=1;i<k;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
