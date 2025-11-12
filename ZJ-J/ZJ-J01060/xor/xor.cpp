#include<bits/stdc++.h>
using namespace std;
double n[1000005];
int h,k;
string a2="",b2="";
string zhuan(double x){
	string str;
	int zheng=int(x);
	double xiao=x-int(x);
	while (zheng>1){
		str=char(zheng%2+48)+str;
		zheng=zheng/2;
	}
	str=char(zheng+48)+str;
	str+='.';
	double sum=0;
	double gg=2;
	while(sum!=xiao){
		if(1/gg+sum>xiao){
			gg*=2;
			str+='0';
		}else{
			gg*=2;
			sum+=1/gg;
			str+='1';
		}
	}
	str+='0';
	return str;
}
string yh(double a1,double b1){
	a2=zhuan(a1);
	b2=zhuan(b1);
	int lena=a2.size();
	int lenb=b2.size();
	int la,lb;
	string ans;
	for(int i=0;i<a2.size();i++){
		if(a2[i]=='.'){
			la=i;
			break;
		}	
	}
	for(int i=0;i<b2.size();i++){
		if(b2[i]=='.'){
			lb=i;
			break;
		}	
	}
	int zza=la-1,zzb=lb-1;
	while (zza>-1&&zzb>-1){
		if((a2[zza]=='1'&&b2[zzb]=='0')||(a2[zza]=='0'&&b2[zzb]=='1')){
			ans='1'+ans;
		}else{
			ans='0'+ans;
		}
		zza-=1;
		zzb-=1;
	}
	if(zza>=0){
		for(int i=zza;i>=0;i--){
			ans=char(a2[i])+ans;
		}
	}else if(zzb>=0){
		for(int i=zzb;i>=0;i--){
			ans=char(b2[i])+ans;
		}
	}
	zza=la+1;
	zzb=lb+1;
	ans+='.';
	while (zza<lena&&zzb<lenb){
		if((a2[zza]=='1'&&b2[zzb]=='0')||(a2[zza]=='0'&&b2[zzb]=='1')){
			ans=ans+'1';
		}else{
			ans=ans+'0';
		}
		zza+=1;
		zzb+=1;
	}
	if(zza==lena){
		for(int i=zzb;i<lenb;i++){
			ans=ans+char(b2[zzb]);
		}
	}else if(zzb==lenb){
		for(int i=zza;i<lena;i++){
			ans=ans+char(a2[zza]);
		}
	}
	return ans;
}
int shi(string u){
	int la;
	for(int i=0;i<u.size();i++){
		if(u[i]=='.'){
			la=i;
			break;	
		}
	}
	int quan=1;
	double sum=0.0;
	int zza=la-1;
	for(int i=zza;i>=0;i--){
		sum+=quan*(int(u[i])-48);
		quan*=2;
	}
	zza=la+1;
	double auan=0.5;
	for(int i=zza;i<u.size();i++){
		sum+=auan*(int(u[i])-48);
		auan=auan/2;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>h>>k;
	for(int i=1;i<=h;i++){
		cin>>n[i];
	}
	int l=1,r=1,ans_0,ans_1=0,i,j;
	for(i=1;i<=h;i++){
		for(j=i;j<=h;j++){
			if(i==j){
				ans_0=n[i];
			}else{
				ans_0=n[i];
				for(int xx=i+1;xx<=j;xx++){
					ans_0=shi(yh(ans_0,n[xx]));
				}
			}
			if(ans_0==k){
				ans_1+=1;
				i=j+1;
			}
		}
		
	}
	cout<<ans_1;
	return 0;
	
}
