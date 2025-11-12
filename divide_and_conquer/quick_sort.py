def quick_sort(arr,low,high):
    if low<high:
        pi = partition(arr,low,high)
        quick_sort(arr,low,pi-1)
        quick_sort(arr,pi+1,high)

def partition(arr,low,high):
    pivot = arr[low]
    i = low
    j = high
    while i<j:
        while i<=high and arr[i]<=pivot:
            i+=1
        while j>=low and arr[j]>pivot:
            j-=1
        if i < j:
            arr[i],arr[j] = arr[j],arr[i]
    arr[low],arr[j] = arr[j],arr[low]
    return j



if __name__ == "__main__":
    lst = []
    while(True):
        print("1.Enter Element\n2.Exit")
        ch = int(input("Enter Choice: "))
        match ch:
            case 1:
                lst.append(int(input("Enter Element: ")))
            case 2:
                break
            case _:
                print("Invalid choice...")
                break
    print("List before sorting: ",end=" ")
    print(lst)
    quick_sort(lst,0,len(lst)-1)
    print("List after sorting: ",end=" ")
    print(lst)