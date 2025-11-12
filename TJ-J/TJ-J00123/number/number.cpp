#include<bits/stdc++.h>
using namespace std;
char s[1000006];
char a[1000006];
int maxans;
bool isshu(char x){
	if(x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'){
		return true;
	}
	return false;
}
int chengfang(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(int i=0;i<sizeof(s);i++){
		if(isshu(s[i])){
			a[cnt]=s[i];
			cnt++;
		}
	}
	do{
		int tmp=0;
		int tmpi=0;
		for(int i=sizeof(a)-1;i>=0;i--){
			if(isshu(a[i])){
				tmp+=(a[i]-'0')*chengfang(10,tmpi);
				tmpi++;
			}
		}
		maxans=max(maxans,tmp);
	}while(next_permutation(a+1,a+cnt));
	cout<<maxans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
