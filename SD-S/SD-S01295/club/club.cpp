#include<bits/stdc++.h>
using namespace std;
struct node{
	int sc1,sc2,sc3;
}c[100005];
node arr1[100005],arr2[100005],arr3[100005];
bool cmp1(const node a,const node b){
	return a.sc1>b.sc1;
}
bool cmp2(const node a,const node b){
	return a.sc2>b.sc2;
}
bool cmp3(const node a,const node b){
	return a.sc3>b.sc3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=10){
			int ans=-1;
			for(int i=1;i<=10;i++){
				c[i].sc1=0;
				c[i].sc2=0;
				c[i].sc3=0;
			}
			for(int i=1;i<=n;i++){
				cin>>c[i].sc1>>c[i].sc2>>c[i].sc3;
			}
			int sum=0;
			int num1=0,num2=0,num3=0;
			for(int i1=0;i1<=2;i1++){
				for(int i2=0;i2<=2;i2++){
					for(int i3=0;i3<=2;i3++){
						for(int i4=0;i4<=2;i4++){
							for(int i5=0;i5<=2;i5++){
								for(int i6=0;i6<=2;i6++){
									for(int i7=0;i7<=2;i7++){
										for(int i8=0;i8<=2;i8++){
											for(int i9=0;i9<=2;i9++){
												for(int i10=0;i10<=2;i10++){
													if(i1==0&&n>=1){
													    num1++;
													}else if(i1==1&&n>=1){
													    num2++;
													}else if(n>=1){
													    num3++;
													}
													if(i2==0&&n>=2){
													    num1++;
													}else if(i2==1&&n>=2){
													    num2++;
													}else if(n>=2){
													    num3++;
													}
													if(i3==0&&n>=3){
													    num1++;
													}else if(i3==1&&n>=3){
													    num2++;
													}else if(n>=3){
													    num3++;
													}
													if(i4==0&&n>=4){
													    num1++;
													}else if(i4==1&&n>=4){
													    num2++;
													}else if(n>=4){
													    num3++;
													}
													if(i5==0&&n>=5){
													    num1++;
													}else if(i5==1&&n>=5){
													    num2++;
													}else if(n>=5){
													    num3++;
													}
													if(i6==0&&n>=6){
													    num1++;
													}else if(i6==1&&n>=6){
													    num2++;
													}else if(n>=6){
													    num3++;
													}
													if(i7==0&&n>=7){
													    num1++;
													}else if(i7==1&&n>=7){
													    num2++;
													}else if(n>=7){
													    num3++;
													}
													if(i8==0&&n>=8){
													    num1++;
													}else if(i8==1&&n>=8){
													    num2++;
													}else if(n>=8){
													    num3++;
													}
													if(i9==0&&n>=9){
													    num1++;
													}else if(i9==1&&n>=9){
													    num2++;
													}else if(n>=9){
													    num3++;
													}
													if(i10==0&&n>=10){
													    num1++;
													}else if(i10==1&&n>=10){
													    num2++;
													}else if(n>=10){
													    num3++;
													}
													if(num1<=n/2&&num2<=n/2&&num3<=n/2){
														if(i1==0){
														    sum+=c[1].sc1;
														}else if(i1==1){
														    sum+=c[1].sc2;
														}else{
														    sum+=c[1].sc3;
														}
														if(i2==0){
														    sum+=c[2].sc1;
														}else if(i2==1){
														    sum+=c[2].sc2;
														}else{
														    sum+=c[2].sc3;
														}
														if(i3==0){
														    sum+=c[3].sc1;
                                                        }else if(i3==1){
														    sum+=c[3].sc2;
														}else{
														    sum+=c[3].sc3;
														}
														if(i4==0){
														    sum+=c[4].sc1;
														}else if(i4==1){
														    sum+=c[4].sc2;
														}else{
														    sum+=c[4].sc3;
														}
														if(i5==0){
														    sum+=c[5].sc1;
														}else if(i5==1){
														    sum+=c[5].sc2;
														}else{
														    sum+=c[5].sc3;
														}
														if(i6==0){
														    sum+=c[6].sc1;
														}else if(i6==1){
														    sum+=c[6].sc2;
														}else{
														    sum+=c[6].sc3;
														}
														if(i7==0){
														    sum+=c[7].sc1;
														}else if(i7==1){
														    sum+=c[7].sc2;
														}else{
														    sum+=c[7].sc3;
														}
														if(i8==0){
														    sum+=c[8].sc1;
														}else if(i8==1){
														    sum+=c[8].sc2;
														}else{
														    sum+=c[8].sc3;
														}
														if(i9==0){
														    sum+=c[9].sc1;
														}else if(i9==1){
														    sum+=c[9].sc2;
														}else{
														    sum+=c[9].sc3;
														}
														if(i10==0){
														    sum+=c[10].sc1;
														}else if(i10==1){
														    sum+=c[10].sc2;
														}else{
														    sum+=c[10].sc3;
														}	
														ans=max(ans,sum);
														sum=0;
													}
													num1=0;
													num2=0;
													num3=0;
													sum=0;
												}				
											}			
										}				
									}				
								}				
							}		
						}				
					}		
				}			
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				cin>>c[i].sc1>>c[i].sc2>>c[i].sc3;
			}
			int num1=0,num2=0,num3=0;
			for(int i=1;i<=n;i++){
				if(max({c[i].sc1,c[i].sc2,c[i].sc3})==c[i].sc1){
					arr1[++num1]=c[i];
				}else if(max({c[i].sc1,c[i].sc2,c[i].sc3})==c[i].sc2){
					arr2[++num2]=c[i];
				}else{
					arr3[++num3]=c[i];
				}
			}
			if(!(num1<=(n/2)&&num2<=(n/2)&&num3<=(n/2))){
				if(num1>(n/2)){
					sort(arr1+1,arr1+1+num1,cmp1);
					for(int i=1;i<=num1;i++){
						if(i>n/2){
							if(arr1[i].sc2>=arr1[i].sc3){
								arr2[++num2]=arr1[i];
							}else{
								arr3[++num3]=arr1[i];
							}
							arr1[i].sc1=0;
						}
					}
				}
				if(num2>(n/2)){
					sort(arr2+1,arr2+1+num2,cmp2);
					for(int i=1;i<=num2;i++){
						if(i>n/2){
							arr3[++num3]=arr2[i];
							arr2[i].sc2=0;
						}
					}
				}
			}
			int sum=0;
			for(int i=1;i<=num1;i++){
				sum+=arr1[i].sc1;
			}
			for(int i=1;i<=num2;i++){
				sum+=arr2[i].sc2;
			}
			for(int i=1;i<=num3;i++){
				sum+=arr3[i].sc3;
			}
			cout<<sum<<"\n";		
		}
	}
	return 0;
}  
