#include<iostream>
using namespace std;

                
   void display(int a[],int i,int n)                             // display array function
    {
        for(i=1;i<=n;i++)
        cout<<"\t"<<a[i];
     }
     
    int mergealgo(int a[],int b[],int c[],int start1,int start2,int end1,int end2)     // Combine definition
    {
        int index=1,i,j,total; 
        i=start1,j=start2;
  
        while(i<=end1 && j<=end2)                      
              {
              
                if(a[i]<b[j])
                i++;
              
                else if(a[i]>b[j])
                j++;
              
                else
                {c[index]=a[i];i++;j++;index++;}           
              
              } 
     
        index=index-1;                                             
        return index;     
                         
    }       
    
    int main()
    {
    
    int a[100],b[100],c[100],n,m,i,total;

    cout<<"Enter size of first array :\t";
    cin>>n;
    cout<<"Enter size of second array :\t";
    cin>>m;
        
                                /* #####AcceptSortedArrays##### */ 
    cout<<"Enter elements for first array:\n";
    for(i=1 ;i<=n;i++)
    {
    cin>>a[i];
    }
    cout<<"Enter elements for second array:\n";
    for(i=1 ;i<=m;i++)
    {
    cin>>b[i];
    }
                               /* #####BeforeIntersection##### */                                     
    cout<<"First Array:\n";    
    display(a,1,n);
    cout<<"\nSecond Array:\n";
    display(b,1,m);
   
    
                               /* #####Merge##### */             
   total=mergealgo(a,b,c,1,1,n,m);
                               /* #####AfterIntersection##### */       
   cout<<"\nElements after intersection are :\n";  
   display(c,1,total);
}