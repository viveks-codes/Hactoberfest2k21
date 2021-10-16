import java.util.Scanner;
class Quicksort
{
  public static void main(String args[])
  {
      Scanner in = new Scanner(System.in);
      int arr[] = new int[20];
      System.out.println("Enter the number of elememts: ");
      int n = in.nextInt();
      for(int i = 0;i<n;i++)
      {
          arr[i]= in.nextInt();
      }
      sort(arr,0,n-1);
      for(int i = 0;i<n;i++)
      {
          System.out.print(arr[i]+" ");
      }
    }
  static void sort(int[] arr,int start, int end)
  {
      int pindex;
      if(start<end)
      {
          pindex = partition(arr,start,end);
          sort(arr,start,pindex-1);
          sort(arr,pindex+1,end);
        }
    }
  static int partition(int[] arr,int start ,int end)
  {
    int pindex, temp1 ,temp2,i;
    int pivot = arr[end];
    pindex = start;
    for(i=start ;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
           temp1=arr[i];
           arr[i]=arr[pindex];
           arr[pindex]=temp1;
           pindex++;
        }
    }
    temp2 = arr[pindex];
    arr[pindex]=arr[end];
    arr[end]=temp2;
    return pindex;
}
}
      
  