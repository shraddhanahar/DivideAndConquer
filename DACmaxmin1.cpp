#include<iostream>
using namespace std;

class maxmin
{
public :
int b[3],max1,min1,max2,min2,*minmax;
int* DACmaxmin(int a[],int i,int j)
{
if(i==j)
    {
    b[1]=b[2]=a[i];
    return b;
    }
if(i+1==j)
    {
    if(a[i]<a[j])
    { b[1]=a[i]; b[2]=a[j]; return b;}
    else
    { b[2]=a[i]; b[1]=a[j]; return b;}
    }
else
    {   
   
                              /* ####divide#### */
    int mid = (i+j)/2;   
        
                              /* ####Conquer#### */   
                              
    minmax=DACmaxmin(a,i,mid);                        
    min1=minmax[1];max1=minmax[2];
    minmax=DACmaxmin(a,mid+1,j);
    min2=minmax[1];max2=minmax[2];
    
                             /* ####CombineLogic#### */ 
    b[1]=min1<min2?min1:min2;                                 
    b[2]=max1>max2?max1:max2;
    return b;
    }
}
};


int main()
{
int a[100],n;
int *minmax;
maxmin ob;
cout<<"Enter no. of elements :\t";
cin>>n;
cout<<"Enter elements : \n";
    for(int i=1;i<=n;i++)
    cin>>a[i];  
minmax = ob.DACmaxmin(a,1,n);        
   
    cout<<"MIN : \t"<< minmax[1]; 
    cout<<"\nMAX : \t"<< minmax[2]<<"\n"; 

}