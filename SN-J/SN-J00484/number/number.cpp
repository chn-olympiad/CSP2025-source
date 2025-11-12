#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen (" number .in","r",stdin);
	freopen (" number .out","w",stdout);
	
	string s;
	cin>>s;
	long long  num=s.size();
	
	char arr[num+1];
	
	long long num_2=0;

	for(int i=0;i<s.size();i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			arr[num_2]=s[i];
			num_2++;
			
		}
	}

	
	for(int i=0;i<num_2-1;i++){
		for(int j=0;j<num_2-1;j++){
			if(arr[j]<arr[j+1]) swap(arr[j],arr[j+1]);
			
		}
	}
	
	for(int i=0;i<num_2;i++){
		cout <<arr[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
