#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//
	char s[1000010]; 
	int ans=0;
	int num[1000010]={0};
	int size_s=1,size_num=0;
	
	cin>>s;
	
	
	for(int i=0;i<size_s;i++){
		if(s[i]>='0' && s[i]<='9'){
			num[size_num]=s[i]-'0';
			size_num++;
			
		}
	}
	sort(num+0,num+size_num-1,cmp);
	for(int i=0;i<=size_num;i++){
		ans*=10;
		ans+=num[i];
	}
	cout<<ans;
	return 0;
}
