
#include<iostream>
using namespace std;

    int Partition(int a[],int start,int end);    // Partition function declaration
    void swap(int *a,int *b);
 
    void display(int a[],int i,int n)                     // display array function
    {
        for(i=1;i<=n;i++)
        {
        cout<<"\t"<<a[i];
        }
    }
    

    void QuickSort(int a[],int start,int end)            // QuickSort 
    {   
        int m,x,y,p=start,q=end,i;      
        if(p<q) 
        {
            m=Partition(a,p,q);                          // Meaningful divide
            QuickSort(a,p,m-1);                     // Conquer
            QuickSort(a,m+1,q);                     // Conquer
        }
    }
    
    
   int Partition(int a[],int p,int q)
   {
    int i=p,j,x=a[p];
        for(j=p+1;j<=q;j++)
        {
           if(a[j]<=x)
            {
            i++;
            swap(&a[i],&a[j]);
            }
        }
        
        swap(&a[i],&a[p]);
        return i;
   }

   void swap(int *a,int *b)
   {
       int x;
        x=*a;
        *a=*b;
        *b=x;
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
                               /* #####QuickSort##### */             
    QuickSort(a,1,n);
                               /* #####AfterSorting##### */ 
    cout<<"\nElements after sorting are :\n";    
    display(a,1,n);   
}