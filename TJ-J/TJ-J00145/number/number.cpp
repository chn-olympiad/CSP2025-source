#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int arr[s.size()+1]={0};
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
		arr[cnt]=s[i]-'0';
		cnt++;
	}
	for(int i=0;i<cnt;i++){
		int max=i;
		for(int j=i;j<cnt;j++){
			if(arr[j]>arr[max]){
				max=j;
			}
		}
		swap(arr[i],arr[max]);
	}
	for(int i=0;i<cnt;i++){
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
