def merge_sort(arr,low,high):
    if low<high:
        mid = (low+high)//2
        merge_sort(arr,low,mid)
        merge_sort(arr,mid+1,high)
        merge(arr,low,mid,high)
    return arr

def merge(arr,low,mid,high):
    sarr = [0] * len(arr)
    i = low
    j = mid+1
    k = low
    while i<= mid and j<=high:
        if arr[i] > arr[j]:
            sarr[k] = arr[j]
            j+=1
        else:
            sarr[k] = arr[i]
            i+=1
        k+=1
    while i<=mid:
        sarr[k] = arr[i] 
        i+=1
        k+=1
    while j<=high:
        sarr[k] = arr[j]
        j+=1
        k+=1
    for i in range(low,high+1):
        arr[i] = sarr[i]


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
    merge_sort(lst,0,len(lst)-1)
    print("List after sorting: ",end=" ")
    print(lst)