#include<bits/stdc++.h>
using namespace std;
bool flag=true;
bool flagb1=true;
bool flagb2=true;
long long n,k,ansb1,ansb2,anss,txt,cnt=1;
long long a[500010],b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)	flag=false;	//特殊A 
		if(a[i]==1)	ansb1++;//特殊B中k=1 
		if(a[i]!=0 && a[i]!=1)	flagb1=false;//特殊B中k=1
		if(a[i]==0){//特殊B中k=0 
			ansb2++;
			b[cnt++]=i;
		}
		if(a[i]!=0 && a[i]!=1)	flagb2=false;//特殊B中k=0
		if(a[i]==k)	anss++;
	}	
	for(int i=1;i<=cnt-2;i++){//特殊B中k=0
		for(int j=b[i];j<=b[i+1];j++){
			if(a[j]==1)	txt++;
		}           
	}
	if(flag==true && k==0){
		cout<<n/2;//特殊A
		return 0;
	}		 
	else if(flagb1==true && k==1)	cout<<ansb1;//特殊B中k=1
	else if(flagb2==true && k==0)	cout<<ansb2+txt/2;//特殊B中k=0
	else	cout<<anss;
	fclose(stdin);	
	fclose(stdout);
	return 0;
}

