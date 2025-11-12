#include<bits/stdc++.h>
using namespace std;
bool flag1=1,flag2=1,flag3=1;
int n,k,a[500010],sum[500010];
void A(){
	cout<<n/2;
}
void B(){
	string s="";
	for(int i=1;i<=n;i++)s+=(a[i]+'0');
	if(k==1){
		int cnt=0;
		while(s.find("1")!=string::npos){
			s.erase(s.find("1"),1);
			cnt++;
		}
		cout<<cnt;
	}
	else{
		int cnt=0;
		while(s.find("0")!=string::npos){
			s.erase(s.find("0"),1);
			cnt++;
		}
		cout<<cnt;
	}
}
void X(){
	int cnt=0;
	
//	int c=0;
	
	map<int,bool>mp;
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]^a[i]);
	/*
	for(int i=1;i<=n;i++)cout<<sum[i]<<" ";
	*/
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			
			/*
			if((k==(sum[i+len-1]^sum[i-1]))){
				cout<<"len="<<len;
				cout<<" i="<<i;
				cout<<" sum[i+len-1]="<<sum[i+len-1];
				cout<<" sum[i-1]="<<sum[i-1];
				cout<<" sum[i+len-1] xor sum[i-1]="<<(sum[i+len-1]^sum[i-1])<<" ";
				cout<<"k="<<k<<" ok="<<(k==(sum[i+len-1]^sum[i-1]))<<"\n";
				c++;
			}
			*/
			if((sum[i+len-1]^sum[i-1])==k){
				bool flag=1;
				for(int l=i;l<=i+len-1;l++)
					if(mp[l]==1){
						flag=0;
						break;
					}
			
				if(flag==1){
					/*
					cout<<"len="<<len;
					cout<<" i="<<i;
					cout<<" sum[i+len-1]="<<sum[i+len-1];
					cout<<" sum[i-1]="<<sum[i-1];
					cout<<" sum[i+len-1] xor sum[i-1]="<<(sum[i+len-1]^sum[i-1])<<" ";
					cout<<"k="<<k<<" ok="<<(k==(sum[i+len-1]^sum[i-1]))<<"\n";
					*/
					cnt++;
					for(int l=i;l<=i+len-1;l++)mp[l]=1;
				}
				
//				else c--;
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)if(!mp[i])cout<<i<<" ";
	cout<<"\n";
	*/
//	cout<<c<<" ";
	cout<<cnt;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	system("fc xor.out xor4.ans");
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=0;
		if(a[i]!=1&&a[i]!=0)flag2=0;
		if(a[i]>255)flag3=0;
	}
	if(flag1)A();
	else if(flag2)B();
//	else if(flag3)C();
	else X();
	return 0;
}
//30pts