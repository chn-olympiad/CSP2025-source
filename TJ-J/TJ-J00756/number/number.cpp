#include<bits/stdc++.h>
using namespace std;
string s;
long long arr[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int idx=0;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'<=9){
			arr[idx]=s[i]-'0';
			idx++;
		}
	}
	for(int i=0;i<idx;i++){
		int max_idx=0;
		for(int i=0;i<idx;i++){
			if(arr[i]>arr[max_idx]){
				max_idx=i;
			}
		}
		cout<<arr[max_idx];
		arr[max_idx]=-1;
	}
	cout<<'\n';
	return 0;
}

