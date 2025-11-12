#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const int M=25;
int num[N][M];
int LenS[N];
int changes(int a,int b){
	if(a==b){
		int ans=0;
		for(int i=0;i<=LenS[a];i++){
			ans+=num[a][i]*pow(2,i);
		}
		return ans;
	}
	int temp[M];
	int lens;
	int j=0;
	lens=LenS[a];
	for(int i=0;i<=LenS[a];i++){
		temp[i]=num[a][i];
	}
	for(int i=a+1;i<=b;i++){
		j=0;
		while(j<=max(lens,LenS[i])){
			if(temp[j] != num[i][j]){
				temp[j]=1;
			}else{
				temp[j]=0;
			}
			j++;
			//cout<<temp[0]<<temp[1]<<endl;
		}
		lens=max(LenS[i],lens);
	}
	//cout<<temp[0]<<temp[1]<<endl;
	//cout<<lens;
	int ans=0;
	for(int i=0;i<=lens;i++){
		ans+=temp[i]*pow(2,i);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int temp,j;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>temp;
		j=0;
		if(temp==0){
			num[i][0]=0;
			LenS[i]=0;
			continue;
		}else{
			while(temp){
				num[i][j]=int(temp-2*int(temp*1.0/2));
				temp/=2;
				
				j++;
			}
			LenS[i]=j-1;
		}
		
	}
	/*
	int tip;
	cin>>tip;
	for(int i=0;i<=LenS[tip];i++){
		cout<<num[tip][i];
	}
	//cout<<" "<<change(tip,tip);
	cout<<"\n";
	*/
	/*
	int left,right;
	cin>>left>>right;
	cout<<LenS[left]<<" "<<LenS[right]<<"\n"<<change(left,right)<<"\n";
	*/
	
	
	
	
	
	
	//cout<<k;
	
	int s=0;
	int l=1,r=1;
	while(r<=n){
		//cout<<l<<" "<<r<<endl;
		//cout<<changes(l,r)<<endl;
		if(changes(l,r)==k){	
			//cout<<l;
			l=r+1;
			r=l;
			s++;
			
			continue;
		}else if(changes(l,r)<k){
			r++;
			continue;
		}else{
			
			
			l=r+1;
			r=l;
			continue;
		}
	}
	
	//cout<<l<<" "<<r<<endl;
	cout<<s;
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
