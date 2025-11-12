#include<cstdio>
#include<algorithm>
int max(int a,int b){
	return (a>b?a:b);
}
int max3(int a,int b,int c){
	return max(a,max(b,c));
}
int mid3(int a,int b,int c){
	if(a>b){
		if(c>a){
			return a;
		}
		else{
			return max(b,c);
		}
	}
	else{
		if(c>b){
			return b;
		}
		else{
			return max(a,c);
		}
	}
}
int t,n,a1,a2,a3,d,l1,l2,l3,b1[100005],b2[100005],b3[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		l1=0,l2=0,l3=0,ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			d=max3(a1,a2,a3)-mid3(a1,a2,a3);
			if(a1>a2){
				if(a1>a3){
					b1[l1]=d;
					ans+=a1;
					l1++;
				}
				else{
					b3[l3]=d;
					ans+=a3;
					l3++;
				}
			}
			else{
				if(a2>a3){
					b2[l2]=d;
					ans+=a2;
					l2++;
				}
				else{
					b3[l3]=d;
					ans+=a3;
					l3++;
				}
			}
		}
		if(l1>n/2){
			std::sort(b1,b1+l1);
			for(int i=0;i<l1-n/2;i++){
				ans-=b1[i];
			}
		}
		if(l2>n/2){
			std::sort(b2,b2+l2);
			for(int i=0;i<l2-n/2;i++){
				ans-=b2[i];
			}
		}
		if(l3>n/2){
			std::sort(b3,b3+l3);
			for(int i=0;i<l3-n/2;i++){
				ans-=b3[i];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
