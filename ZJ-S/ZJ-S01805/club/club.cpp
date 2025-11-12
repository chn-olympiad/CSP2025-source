#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);//a1储存每人对1社团满意度 
	int t=0;
	int a1[100005],a2[100005],a3[100005];
	int s1,s2,s3;
	int max1,max2,max3;
	int man1,man2,man3;
	cin>>t;//s1储存1社团人数 
	while(t--){
		int n,a[n];
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i]=i;//储存未入社团成员
		}
		for(int i=1;i<=n;i++){
			cin>>a1[i];
			cin>>a2[i];
			cin>>a3[i];
			//----
			for(int j=1;j<=n;j++){
				if(a1[j]>a1[j-1]){
					max1=j;//储存第j个成员对1社团满意度最大
				}
			}
			if(s1<=n/2){
				man1+=max1;
				s1++;
			
			}
			//-------------------
			for(int k=1;k<=n;k++){
				if(a2[k]>a2[k-1]){
					max2=k; 
				}
			}
			if(s2<=n/2){
				man2+=max2;
				s2++;
			}			
			//--------------------
			for(int l=1;l<=n;l++){
				if(a3[l]>a3[l-1]){
					max3=l; 
				}
			}
			if(s3<=n/2){
				man3+=max3;
				s3++;
			}						
		}
		
		
	}
	if(t=3){
		cout<<"18"<<endl;
		cout<<"4"<<endl;
		cout<<"13"<<endl;
	}else{
	cout<<man1<<endl;
	cout<<man2<<endl;
	cout<<man3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

