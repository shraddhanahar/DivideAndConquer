#include<iostream>
using namespace std;

    void display(int a[],int i,int n)                     // display array function
    {
        for(i=1;i<=n;i++)
        {
        cout<<"\t"<<a[i];
        }
    }
    
    
    void BinarySort(int a[],int start,int end,int key)   //BinarySort logic
    {
    int i=start,j=end,mid;
    
     if(i<j)
        {
        mid=(i+j)/2;
        
        if(a[mid]==key)
        { 
        cout<<"\nKey present at "<<mid<<" positon";
        }
    
        else if(a[mid]<key)
        BinarySort(a,mid+1,j,key);
        
        else
        BinarySort(a,i,mid,key);
        }
        
     else if(i==j)
      {
       if(a[i]==key)      
       { cout<<"\nKey present at "<<i<<" positon";}
       else
       { cout<<"\nKey not present";}
      }
     
    }
int main()
{
 int a[100],n,key;char ch='yes';
 
 cout<<"\nEnter size of array :\t";
 cin>>n;
 
    cout<<"\nEnter elements in sorted order:\n";         
    for(int i=1 ;i<=n;i++)
    {
    cin>>a[i];
    }
    cout<<"\nElements are:\n";
    display(a,1,n);
    while(ch=='yes')                                            //while loop if you want to search more elements
    {
    cout<<"\nEnter element to be searched :\n"; 
    cin>>key;
    
    BinarySort(a,1,n,key);
    cout<<"\nDo you want to search more?Type yes or no :";
    cin>>ch;
   }
}