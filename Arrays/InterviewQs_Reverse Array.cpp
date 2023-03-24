//STL Command
void reverse(int arr[], int n)  
{  
    reverse(arr, arr + n );   
} 

//Loop
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}   
