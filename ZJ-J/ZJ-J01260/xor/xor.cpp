#include<bits/stdc++.h>
using namespace std;
long long sum;
int rp=INT_MAX;
int n,k;
int b[500010],c[500010];
string s[260];
int xorr(int a,int b){
	string s1,s2;
	if(a<256) s1=s[a];
	else{
		while(a){
			s1+=char(a%2+'0');
			a/=2;
		}
	}
	if(b<256) s2=s[b];
	else{
		while(b){
			s2+=char(b%2+'0');
			b/=2;
		}
	}
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	
	if(s1.size()<s2.size()){
		reverse(s1.begin(),s1.end());
		while(s1.size()<s2.size()) s1+='0';
		reverse(s1.begin(),s1.end());
	}
	if(s2.size()<s1.size()){
		reverse(s2.begin(),s2.end());
		while(s2.size()<s1.size()) s2+='0';
		reverse(s2.begin(),s2.end());
	}
	
	string s3;
	for(int i=0;i<s1.size();i++){
		if((s1[i]=='0'&&s2[i]!='0')||(s2[i]=='0'&&s1[i]!=0)) s3+='1';
		else s3+='0';
	}
	
	int sum=0;
	reverse(s3.begin(),s3.end());
	for(int i=0;i<s3.size();i++) sum+=(s3[i]-'0')*pow(2,i);
	return sum;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=256;i++) {
		int a=i;
		while(a){
			s[i]+=char(a%2+'0');
			a/=2;
		}
	}
	for(int i=1;i<=n;i++){cin>>b[i];if(b[i]==k) {sum++;c[i]=1;}}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			int ans=b[j];
			
			for(int k=j+1;k<=i+j;k++){
				if(c[k]==1||c[j]==1) {ans=-1000;break;}
				ans=xorr(ans,b[k]);
			}
			if(ans==k) {sum++;for(int k=j;k<=i+j;k++) c[k]=1;}
		}
	}
	cout<<sum;
	return 0;
}
