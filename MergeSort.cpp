#include<iostream>
using namespace std;

    void mergealgo(int a[],int start,int mid,int end);    // merging function declaration
 
 
    void display(int a[],int i,int n)                     // display array function
    {
        for(i=1;i<=n;i++)
        {
        cout<<"\t"<<a[i];
        }
    }
    

    void mergeSort(int a[],int start,int end)            // mergeSort 
    {   
      int mid;
   
        if(start<end)
        {
            mid=(start+end)/2;                          // Blind divide
            mergeSort(a,start,mid);                     // Conquer
            mergeSort(a,mid+1,end);                     // Conquer
            mergealgo(a,start,mid,end);                 // Combine
        }
   }


void mergealgo(int a[],int start,int mid,int end)      // Combine definition
{
    int p,j=mid+1,b[100],index=start,i=start;
      
        while(i<=mid && j <= end)                      
        {
            if(a[i]<a[j])
            {  b[index]=a[i];i++; }
            else
            { b[index]=a[j];j++; }
            index++;
        }                                              //comparing and storing until one of the part vanishes
    
       if(i>mid)
        {
            while(j<=end)
            { b[index]=a[j]; index++; j++; }
        }                                              //if first half of array finishes ,store all left elements from second half 
     
        else
        {
            while(i<=mid)
            { b[index]=a[i]; index++; i++; }
        }                                                //if second half of array finishes ,store all left elements from first half 
        
        p=start;
        while(p<index)
        { a[p]=b[p]; p++; }                             //copy back elements in a array
}    
    


int main()
{
int a[100],n,i;

    cout<<"Enter size of array :\t";
    cin>>n;
        
                                /* #####AcceptArray##### */ 
    cout<<"Enter elements :\n";
    for(int i =1 ;i<=n;i++)
    {
    cin>>a[i];
    }
                               /* #####BeforeSorting##### */                                     
    cout<<"Elements before sorting are :\n";    
    display(a,1,n);
                               /* #####MergeSort##### */             
    mergeSort(a,1,n);
                               /* #####AfterSorting##### */ 
    cout<<"\nElements after sorting are :\n";    
    display(a,1,n);   
}
