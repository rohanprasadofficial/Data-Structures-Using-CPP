#include <iostream.h>


int main()
{
int i,j,k,arr[32][5];
float W[5],B[5],KW,TW[32],TB[32],MAX;

for(i=0;i<32;i++){for(j=0;j<5;j++){arr[i][j]=0;}}
for(i=0;i<32;i++){j=0;
                    k=i;
             while(k>0){arr[i][j]=k%2;j=j+1;
                        k=k/2;}}
for(i=0;i<32;i++){for(j=0;j<5;j++){cout<<arr[i][4-j]<<"   ";}cout<<endl<<endl;}

cout<<"Enter the weight of Knapsack: ";
cin>>KW;
cout<<endl; 
//input the weight and benefit of each item
for(i=0;i<5;i++)
{    
     cout<<"Weight item "<< i+1 <<"= ";
     cin>>W[i];
     cout<<"Benefit item "<< i+1 <<"= ";
     cin>>B[i];
}
for(i=0;i<32;i++){TW[i]=0;TB[i]=0;for(j=0;j<5;j++){TW[i]+=arr[i][4-j]*W[j];TB[i]+=arr[i][4-j]*B[j];}
                              if(TW[i]>KW)TB[i]=0;
                  }


       MAX=0;for(i=0;i<32;i++)  {if(TB[i]>MAX)MAX=TB[i];}
   cout<<"The higest benefit is="<<MAX<<endl<<endl;                    



    
    
    return 0;
}

