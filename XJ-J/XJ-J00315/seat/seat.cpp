 #include<bits/stdc++.h>
 using namespace std;
 int n,m,x;int cnt=1,pos1,pos2=1;
 int main()
 {
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     cin>>n>>m;
     cin>>x;
     for(int i=1;i<m*n;i++)
     {
         int y;
         cin>>y;
         if(y>x)cnt++;
     }
     if(cnt%n==0)pos1=cnt/n;
     else pos1=cnt/n+1;
     if(pos1%2==1)
     {
         if(cnt%n!=0)pos2=cnt%n;
         else pos2=cnt%(n+1);
     }
     if(pos1%2==0) pos2=n-cnt%(n+1);
     cout<<pos1<<" "<<pos2;
     return 0;
 }
